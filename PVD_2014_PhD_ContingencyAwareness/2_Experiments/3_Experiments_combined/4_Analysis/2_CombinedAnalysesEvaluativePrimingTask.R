############### DATA ANALYSIS EPT EXP 1 AND 2 COMBINED ##############
## Last update: 18/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)    # package Version 3.17.3
library(lme4)     # package Version 1.1.12
library(car)
library(effects)

##### 1. Read in Evaluative Priming Task Data of Experiment 1 and 2 ####

## read in Data Exp 1

Data1<-read.table("../../1_Experiment1/3_DataDerived/DataEPT.txt", header=T)
describe(Data1) # 62 pps - 17 variables - 7340 lines of data 
Data1<-Data1[,-c(2:5,8,10:12,14, 16)]
head(Data1)
colnames(Data1)=c("ppn", "tfac", "fac", "ttype","rt","target", "cont_corr")

## read in Data Exp 2

Data2<-read.table("../../2_Experiment2/3_DataDerived/DataEPT.txt", header=T)
describe(Data2) # 62 pps - 17 variables - 7392 lines of data 
Data2<-Data2[,-c(2:5,8,10:12,14, 16)]
head(Data2)
colnames(Data2)=c("ppn", "tfac", "fac", "ttype","rt","target", "cont_corr")
Data2$cont_corr<-ifelse(Data2$cont_corr==4,3,Data2$cont_corr)
Data2$ppn<-Data2$ppn+62

## Add variable Exp indicating which experiment pps participated in: 1 or 2
Data1$Exp<-1
Data2$Exp<-2

## Merge Data files Exp 1 and 2
combData<-rbind(Data1, Data2) 
describe(combData)

##### 2. Prepare Lmer Analyses Explicit Ratings ####

## factorize variables

combData$ppn<-factor(combData$ppn)
combData$fac<-factor(combData$fac) ## Nr of the face that is used as prime: 0-7
combData$tfac<-factor(combData$tfac) ## Type face that is used as prime: 1=approached face 2 =avoided face
combData$ttype<-factor(combData$ttype) ## Target type: 1 = pos word 0 =neg word
combData$target<-factor(combData$target) ## specific target word that is used: 12 possible words: aangenaam, humeurig,..
combData$cont_corr<-factor(combData$cont_corr) ## What action does the participant indicate that this face is used with: 1 = correct (e.g., approached if approached) 2= incorrect (e.g., approached if avoided) 3 = both actions an equal number of times 

##### 3. Perform Lmer Analyses EPT RTs ####

## Test effects of fixed factors Face Type, Target Type and Contingency Awareness

fit1<-lmer(rt~ttype*tfac*cont_corr+(1|ppn)+(1|target), data=combData, contrasts = list(ttype="contr.sum", tfac="contr.sum", cont_corr="contr.sum"))
summary(fit1)
Anova(fit1, type='III') 
effect('ttype:tfac:cont_corr', fit1)# p .016 3-way interaction

## Explore 3-way interaction of Face Type x TargetTypexCOntingency Awareness

# contingency correct:
combData1<-combData[combData$cont_corr==1,] 

fit1_1<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=combData1, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit1_1)
Anova(fit1_1, type='III')            # p<.001: effect of Target TypexFace Type

# contingency incorrect:
combData2<-combData[combData$cont_corr==2,] 

fit1_2<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=combData2, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit1_2)
Anova(fit1_2, type='III')            # p.82: effect of Target TypexFace Type

# contingency indiscriminate:
combData3<-combData[combData$cont_corr==3,] 

fit1_3<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=combData3, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit1_3)
Anova(fit1_3, type='III')            # p.66: effect of Target TypexFace Type

##### 4. Perform T-test Analyses EPT RTs ####

## for contingency correct faces
# approached and pos target:
D1<-combData1[combData1$tfac==1&combData1$ttype==1,] 
D2<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D2)=c("ppn", "pos_ap")

# approached and neg target
D1<-combData1[combData1$tfac==1&combData1$ttype==0,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
D2$neg_ap<-D3$x

# avoided and pos target
D1<-combData1[combData1$tfac==2&combData1$ttype==1,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D3)=c("ppn", "pos_av")
describe(D3)
DataAggregated<-merge(D2,D3,by="ppn")
describe(DataAggregated)

# avoided and neg target
D1<-combData1[combData1$tfac==2&combData1$ttype==0,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D3)=c("ppn", "neg_av")
DataAggregated1<-merge(DataAggregated,D3,by="ppn")

DataAggregated1$ap<-DataAggregated1$neg_ap-DataAggregated1$pos_ap
DataAggregated1$av<-DataAggregated1$neg_av-DataAggregated1$pos_av
DataAggregated1$a<-DataAggregated1$ap-DataAggregated1$av
t.test(DataAggregated1$a)   # approach face more positive than avoid p<.001
m1<-mean(DataAggregated1$a)
s1<-sd(DataAggregated1$a)
d<-(m1)/(s1)                # effect size d = 0.38

## for contingency incorrect faces
# approached and pos target:
D1<-combData2[combData2$tfac==1&combData2$ttype==1,] 
D2<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D2)=c("ppn", "pos_ap")

# approached and neg target:
D1<-combData2[combData2$tfac==1&combData2$ttype==0,]
D3<-aggregate(D1$rt, list(D1$ppn), mean)
D2$neg_ap<-D3$x

# avoided and pos target:
D1<-combData2[combData2$tfac==2&combData2$ttype==1,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D3)=c("ppn", "pos_av")
DataAggregated<-merge(D2,D3,by="ppn")

# avoided and neg target:
D1<-combData2[combData2$tfac==2&combData2$ttype==0,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D3)=c("ppn", "neg_av")
DataAggregated2<-merge(DataAggregated,D3,by="ppn")

DataAggregated2$ap<-DataAggregated2$neg_ap-DataAggregated2$pos_ap
DataAggregated2$av<-DataAggregated2$neg_av-DataAggregated2$pos_av
DataAggregated2$a<-DataAggregated2$ap-DataAggregated2$av
t.test(DataAggregated2$a)    # approach face more positive than avoid p.95
m1<-mean(DataAggregated2$a)
s1<-sd(DataAggregated2$a)
d<-(m1)/(s1)                 # effect size d = 0.01

## for contingency indiscriminate faces
# approached and pos target:
D1<-combData3[combData3$tfac==1&combData3$ttype==1,] 
D2<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D2)=c("ppn", "pos_ap")

# approached and neg target:
D1<-combData3[combData3$tfac==1&combData3$ttype==0,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
D2$neg_ap<-D3$x

# avoided and pos target:
D1<-combData3[combData3$tfac==2&combData3$ttype==1,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D3)=c("ppn", "pos_av")
DataAggregated<-merge(D2,D3,by="ppn")

# avoided and neg target:
D1<-combData3[combData3$tfac==2&combData3$ttype==0,] 
D3<-aggregate(D1$rt, list(D1$ppn), mean)
colnames(D3)=c("ppn", "neg_av")
DataAggregated3<-merge(DataAggregated,D3,by="ppn")

DataAggregated3$ap<-DataAggregated3$neg_ap-DataAggregated3$pos_ap
DataAggregated3$av<-DataAggregated3$neg_av-DataAggregated3$pos_av
DataAggregated3$a<-DataAggregated3$ap-DataAggregated3$av
t.test(DataAggregated3$a)    # approach face more positive than avoid p.29
m1<-mean(DataAggregated3$a)
s1<-sd(DataAggregated3$a)
d<-(m1)/(s1)                 # effect size d = 0.15