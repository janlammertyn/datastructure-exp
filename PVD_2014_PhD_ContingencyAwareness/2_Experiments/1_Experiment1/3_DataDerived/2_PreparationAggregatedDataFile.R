############### DATA PREPARATION PART 2: Prepare Aggregated Data File ##############
## Last update: 10/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)
library(psy)

##### 1. Read in Raw Data : explicitdata.rtd ####

Data<-read.table("../2_DataRaw/explicitdata.rtd", header=T) 
describe(Data) # 63 pps - 83 variables - 63 lines of data (1/pp)

##### 2. exclude pp19 for making too many errors in EPT ####

Data<-Data[!Data$pp==19, ]

##### 3. compute explicit rating scores for each face  ####

#compute explicit rating scores as average of friendliness and liking rating

Data$f1_exp<-(Data$X0ra+Data$X0vr)/2
Data$f2_exp<-(Data$X1ra+Data$X1vr)/2
Data$f3_exp<-(Data$X2ra+Data$X2vr)/2
Data$f4_exp<-(Data$X3ra+Data$X3vr)/2
Data$f5_exp<-(Data$X4ra+Data$X4vr)/2
Data$f6_exp<-(Data$X5ra+Data$X5vr)/2
Data$f7_exp<-(Data$X6ra+Data$X6vr)/2
Data$f8_exp<-(Data$X7ra+Data$X7vr)/2

## calculate mean cronbach's alpha for the 8 explicit rating scores

head(Data)
c1<-cronbach(Data[,6:7])
c2<-cronbach(Data[,14:15])
c3<-cronbach(Data[,22:23])
c4<-cronbach(Data[,30:31])
c5<-cronbach(Data[,38:39])
c6<-cronbach(Data[,46:47])
c7<-cronbach(Data[,54:55])
c8<-cronbach(Data[,62:63])

c<-(c1$alpha+c2$alpha+c3$alpha+c4$alpha+c5$alpha+c6$alpha+c7$alpha+c8$alpha)/8
c # mean Cronbach's alpha = 0.62
alpha<-c(c1$alpha,c2$alpha,c3$alpha,c4$alpha,c5$alpha,c6$alpha,c7$alpha,c8$alpha)
sd(alpha)

##### 4. compute new contingency awareness variables ####

# Compute contingency correct variable cc per face (= 1 if contingency correct , 2 = incorrect, 3 =indiscriminate )

Data$f1_cc<-ifelse(Data$X0ca==1, 1, 2)
Data$f2_cc<-ifelse(Data$X1ca==1, 1, 2)
Data$f3_cc<-ifelse(Data$X2ca==1, 1, 2)
Data$f4_cc<-ifelse(Data$X3ca==1, 1, 2)
Data$f5_cc<-ifelse(Data$X4ca==1, 1, 2)
Data$f6_cc<-ifelse(Data$X5ca==1, 1, 2)
Data$f7_cc<-ifelse(Data$X6ca==1, 1, 2)
Data$f8_cc<-ifelse(Data$X7ca==1, 1, 2)

Data$f1_cc<-ifelse(Data$X0ac==3, 3, Data$f1_cc)
Data$f2_cc<-ifelse(Data$X1ac==3, 3, Data$f2_cc)
Data$f3_cc<-ifelse(Data$X2ac==3, 3, Data$f3_cc)
Data$f4_cc<-ifelse(Data$X3ac==3, 3, Data$f4_cc)
Data$f5_cc<-ifelse(Data$X4ac==3, 3, Data$f5_cc)
Data$f6_cc<-ifelse(Data$X5ac==3, 3, Data$f6_cc)
Data$f7_cc<-ifelse(Data$X6ac==3, 3, Data$f7_cc)
Data$f8_cc<-ifelse(Data$X7ac==3, 3, Data$f8_cc)

# Compute contingency correct variable cc overall : total nr of faces correct

Data$cc<-0
Data$cc<-ifelse(Data$f1_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f2_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f3_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f4_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f5_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f6_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f7_cc==1, Data$cc+1, Data$cc)
Data$cc<-ifelse(Data$f8_cc==1, Data$cc+1, Data$cc)
Data$cc_p<-(Data$cc/8)*100

# Compute contingency incorrect variable ci overall: total nr of faces incorrect 

Data$ci<-0
Data$ci<-ifelse(Data$f1_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f2_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f3_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f4_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f5_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f6_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f7_cc==2, Data$ci+1, Data$ci)
Data$ci<-ifelse(Data$f8_cc==2, Data$ci+1, Data$ci)
Data$ci_p<-(Data$ci/8)*100

# Compute contingency indiscriminate variable dbt overall: total nr of faces participants indicated 'both actions equal' 

Data$dbt<-0
Data$dbt<-ifelse(Data$f1_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f2_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f3_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f4_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f5_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f6_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f7_cc==3, Data$dbt+1, Data$dbt)
Data$dbt<-ifelse(Data$f8_cc==3, Data$dbt+1, Data$dbt)
Data$dbt_p<-(Data$dbt/8)*100

##### 5. write away aggregated data file #######

write.table(Data, "DataAggregated.txt", sep="\t")