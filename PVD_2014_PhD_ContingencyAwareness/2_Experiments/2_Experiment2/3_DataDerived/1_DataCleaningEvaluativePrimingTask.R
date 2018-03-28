############### DATA PREPARATION PART 1: Data Cleaning EPT ##############
## Last update: 17/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)

##### 1. Read in Raw Data : primedata.rtd ####

Data<-read.table("../2_DataRaw/primedata.rtd", header=T)
describe(Data) # 64 pps - 15 variables - 8192 lines of data (128 trials /pp)

##### 2. Do participant exclusion #### 

# compute participant exclusion cut-off point based on mean number of errors

aggregate(cor~ppn, data=Data, mean)
t<-tapply(Data$cor, Data$ppn, mean)
e<-1-t
mean(e)+(2.5*sd(e)) # 13.90 % x 126 = cut-off point 17 trials incorrect

# exclude 2 pps with >2.5SDs above mean: pp 30 and 64

ar<-table(Data$ppn,Data$cor)
c1<-as.data.frame(ar)
c1<-c1[c1$Var2==0,]
c2<-c1[c1$Freq>17,]
Data<-Data[!(Data$ppn %in% c2$Var1),]

##### 3. Do trial exclusion ####

# compute cut-off: trials 2.5sds faster or slower than the participants' mean

t<-tapply(Data$rt, Data$ppn, mean)
sd<-tapply(Data$rt, Data$ppn, sd)
up<-t+2.5*sd
low<-t-2.5*sd

# exclude trials for each participant on the basis of personal cut-off

up1<-up[1]
low1<-low[1]
Data1<-Data[Data$ppn==1, ]
Data1<-Data1[Data1$rt<up1&Data1$rt>low1, ]

for (i in 2:29){
  upi<-up[i]
  lowi<-low[i]
  Data_<-Data[Data$ppn==i,]
  Data_<-Data_[Data_$rt<upi&Data_$rt>lowi, ]
  Data1<-rbind(Data1,Data_)
}

for (i in 30:63){
  upi<-up[i]
  lowi<-low[i]
  Data_<-Data[Data$ppn==i+1,] # skip over pp 30
  Data_<-Data_[Data_$rt<upi&Data_$rt>lowi, ]
  Data1<-rbind(Data1,Data_)
}

# compute nr of trials excluded
 
total<-62*128
newtotal<-nrow(Data1)
pct<-newtotal/total
1-pct # 2.73 % of trials excluded

# exclude all error trials

Data1<-Data1[Data1$cor==1,]
oldtotal<-newtotal
newtotal<-nrow(Data1)
1-(newtotal/oldtotal) #4.24% of trials excluded

##### 4. Compute Contingency awareness variable #######

head(Data1)
Data1$contingency_aware<-ifelse((Data1$ppn==1&(Data1$fac==1|Data1$fac==2|Data1$fac==3))|(Data1$ppn==2&(Data1$fac==0|Data1$fac==3|Data1$fac==4))|(Data1$ppn==3&(Data1$fac==0|Data1$fac==2|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7)) |(Data1$ppn==4 &(Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==7))|(Data1$ppn==5) |(Data1$ppn==6&(Data1$fac==0))|(Data1$ppn==7&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7))|(Data1$ppn==8&(Data1$fac==4|Data1$fac==5|Data1$fac==6))| (Data1$ppn==9&(Data1$fac==0|Data1$fac==1|Data1$fac==5))| (Data1$ppn==10&(Data1$fac==2|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7))|(Data1$ppn==12&(Data1$fac==0|Data1$fac==2|Data1$fac==3|Data1$fac==7))| (Data1$ppn==13)|(Data1$ppn==14&(Data1$fac==2))| (Data1$ppn==15&(Data1$fac==2))| (Data1$ppn==16&(Data1$fac==0|Data1$fac==4|Data1$fac==5))|(Data1$ppn==17&(Data1$fac==4|Data1$fac==5))|(Data1$ppn==18&(Data1$fac==6))|(Data1$ppn==19&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==6))| (Data1$ppn==20&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==5))|(Data1$ppn==21&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==3|Data1$fac==6|Data1$fac==7))| (Data1$ppn==22&(Data1$fac==0))| (Data1$ppn==23&(Data1$fac==6))|(Data1$ppn==24&(Data1$fac==2|Data1$fac==4|Data1$fac==5|Data1$fac==7))| (Data1$ppn==25&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==3|Data1$fac==5|Data1$fac==6|Data1$fac==7))| (Data1$ppn==26&(Data1$fac==0|Data1$fac==1))| (Data1$ppn==27&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==6|Data1$fac==7))|(Data1$ppn==28&(Data1$fac==0|Data1$fac==2|Data1$fac==3|Data1$fac==5|Data1$fac==6|Data1$fac==7))|(Data1$ppn==29&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==7))| (Data1$ppn==30&(Data1$fac==2|Data1$fac==3|Data1$fac==5|Data1$fac==6))| (Data1$ppn==31)| (Data1$ppn==32&(Data1$fac==0|Data1$fac==2|Data1$fac==5|Data1$fac==7))| (Data1$ppn==33&(Data1$fac==0|Data1$fac==1|Data1$fac==4|Data1$fac==5|Data1$fac==7))| (Data1$ppn==34&(Data1$fac==1|Data1$fac==4|Data1$fac==5|Data1$fac==7))| (Data1$ppn==35&(Data1$fac==1|Data1$fac==2|Data1$fac==3|Data1$fac==5|Data1$fac==6|Data1$fac==7))| (Data1$ppn==36&(Data1$fac==0|Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==6))| (Data1$ppn==37&(Data1$fac==0|Data1$fac==5|Data1$fac==6))| (Data1$ppn==38&(Data1$fac==1|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==7))| (Data1$ppn==39&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==6))| (Data1$ppn==40&(Data1$fac==3|Data1$fac==5|Data1$fac==7))|(Data1$ppn==41&(Data1$fac==0|Data1$fac==5))|(Data1$ppn==43&(Data1$fac==1|Data1$fac==3|Data1$fac==5|Data1$fac==6|Data1$fac==7))| (Data1$ppn==44&(Data1$fac==0|Data1$fac==1|Data1$fac==5))| (Data1$ppn==45&(Data1$fac==0|Data1$fac==2|Data1$fac==3|Data1$fac==5|Data1$fac==6)) |(Data1$ppn==46&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==6|Data1$fac==7)) |(Data1$ppn==47&(Data1$fac==0|Data1$fac==2|Data1$fac==5))|(Data1$ppn==48&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==3|Data1$fac==5|Data1$fac==6|Data1$fac==7)) |(Data1$ppn==49&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4))|(Data1$ppn==50&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4)) |(Data1$ppn==51) |(Data1$ppn==52&(Data1$fac==0|Data1$fac==2)) |(Data1$ppn==53&(Data1$fac==1|Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7)) |(Data1$ppn==54&(Data1$fac==2|Data1$fac==5|Data1$fac==7))|(Data1$ppn==55&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7)) |(Data1$ppn==56&(Data1$fac==1|Data1$fac==2|Data1$fac==4))|(Data1$ppn==57&(Data1$fac==3))|(Data1$ppn==58&(Data1$fac==0))|(Data1$ppn==59&(Data1$fac==0|Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==6))|(Data1$ppn==60&(Data1$fac==0|Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7))|(Data1$ppn==61&(Data1$fac==0|Data1$fac==6|Data1$fac==7))|(Data1$ppn==62&(Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7)),0,1)
Data1$contingency_aware<-ifelse((Data1$ppn==63&(Data1$fac==0|Data1$fac==2|Data1$fac==7)),0,Data1$contingency_aware)
Data1$contingency_correct<-ifelse(Data1$contingency_aware==1,1,0)

Data1$contingency_correct<-ifelse((Data1$ppn==2 & (Data1$fac==4))|(Data1$ppn==3 & (Data1$fac==2|Data1$fac==4)) |(Data1$ppn==4 & (Data1$fac==3))|(Data1$ppn==7 & (Data1$fac==0|Data1$fac==7))|(Data1$ppn==8& (Data1$fac==2))|(Data1$ppn==12 &(Data1$fac==0|Data1$fac==7))|(Data1$ppn==13 & (Data1$fac==2))|(Data1$ppn==19 &(Data1$fac==4))|(Data1$ppn==20&(Data1$fac==0))|(Data1$ppn==21&(Data1$fac==2|Data1$fac==6))|(Data1$ppn==24&(Data1$fac==4|Data1$fac==7))|(Data1$ppn==25 & (Data1$fac==5))|(Data1$ppn==26&(Data1$fac==1))|(Data1$ppn==27&(Data1$fac==1))|(Data1$ppn==28&(Data1$fac==2|Data1$fac==7|Data1$fac==5))|(Data1$ppn==30&(Data1$fac==3))|(Data1$ppn==32 &(Data1$fac==2|Data1$fac==5|Data1$fac==7))|(Data1$ppn==33&(Data1$fac==0))|(Data1$ppn==35&(Data1$fac==1))|(Data1$ppn==36&(Data1$fac==3))|(Data1$ppn==43&(Data1$fac==5))|(Data1$ppn==44&(Data1$fac==0|Data1$fac==1|Data1$fac==5))|(Data1$ppn==46&(Data1$fac==2|Data1$fac==4|Data1$fac==7))|(Data1$ppn==50&(Data1$fac==1))|(Data1$ppn==53&(Data1$fac==5|Data1$fac==7))|(Data1$ppn==56 &(Data1$fac==2))|(Data1$ppn==59&(Data1$fac==1|Data1$fac==2|Data1$fac==4|Data1$fac==6))|(Data1$ppn==62&(Data1$fac==2|Data1$fac==3|Data1$fac==6|Data1$fac==7 ))|(Data1$ppn==64 &(Data1$fac==2)),3,Data1$contingency_correct)
Data1$contingency_correct<-ifelse((Data1$ppn==2 & (Data1$fac==0))|(Data1$ppn==3 & (Data1$fac==0|Data1$fac==5)) |(Data1$ppn==4 & (Data1$fac==2|Data1$fac==7))|(Data1$ppn==5)|(Data1$ppn==7&(Data1$fac==2|Data1$fac==5|Data1$fac==6))|(Data1$ppn==8&(Data1$fac==5))|(Data1$ppn==12&(Data1$fac==2))|(Data1$ppn==13&(Data1$fac==0|Data1$fac==1|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7))|(Data1$ppn==14&(Data1$fac==2))|(Data1$ppn==15&(Data1$fac==2))|(Data1$ppn==16&(Data1$fac==0))|(Data1$ppn==18&(Data1$fac==6))|(Data1$ppn==19&(Data1$fac==2|Data1$fac==6))|(Data1$ppn==20&(Data1$fac==1|Data1$fac==2|Data1$fac==5))|(Data1$ppn==21&(Data1$fac==0|Data1$fac==7))|(Data1$ppn==22&(Data1$fac==0))|(Data1$ppn==24&(Data1$fac==2|Data1$fac==5))|(Data1$ppn==25&(Data1$fac==0|Data1$fac==6|Data1$fac==7))|(Data1$ppn==27&(Data1$fac==2|Data1$fac==4|Data1$fac==7))|(Data1$ppn==29&(Data1$fac==0|Data1$fac==1|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==7))|(Data1$ppn==30&(Data1$fac==5))|(Data1$ppn==31)|(Data1$ppn==35&(Data1$fac==2|Data1$fac==5))|(Data1$ppn==36&(Data1$fac==2|Data1$fac==6))|(Data1$ppn==37&(Data1$fac==5))|(Data1$ppn==38&(Data1$fac==3))|(Data1$ppn==39&(Data1$fac==0|Data1$fac==2))|(Data1$ppn==41&(Data1$fac==0))|(Data1$ppn==43&(Data1$fac==3|Data1$fac==7))|(Data1$ppn==45&(Data1$fac==0|Data1$fac==3|Data1$fac==5|Data1$fac==6))|(Data1$ppn==46&(Data1$fac==0))|(Data1$ppn==47&(Data1$fac==2))|(Data1$ppn==48&(Data1$fac==1))|(Data1$ppn==49&(Data1$fac==1|Data1$fac==4))|(Data1$ppn==51)|(Data1$ppn==53&(Data1$fac==2|Data1$fac==3))|(Data1$ppn==54&(Data1$fac==2|Data1$fac==5|Data1$fac==7))|(Data1$ppn==55&(Data1$fac==1|Data1$fac==2|Data1$fac==4))|(Data1$ppn==56&(Data1$fac==3|Data1$fac==5))|(Data1$ppn==60&(Data1$fac==0|Data1$fac==2|Data1$fac==3|Data1$fac==4|Data1$fac==5|Data1$fac==6|Data1$fac==7))|(Data1$ppn==61&(Data1$fac==0|Data1$fac==7))|(Data1$ppn==63&(Data1$fac==0|Data1$fac==7))|(Data1$ppn==64&(Data1$fac==5)),4,Data1$contingency_correct)
Data1$contingency_correct<-ifelse(Data1$contingency_correct==0,2,Data1$contingency_correct)
table(Data1$contingency_correct)

##### 5. write away final EPT data file #######

write.table(Data1, "DataEPT.txt", sep="\t") 
describe(Data1)