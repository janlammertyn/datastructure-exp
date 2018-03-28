############### DATA ANALYSIS RATINGS EXP 1 AND 2 COMBINED ##############
## Last update: 18/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)    # package Version 3.17.3
library(lme4)     # package Version 1.1.12
library(car)
library(effects)

##### 1. Read in Explicit Rating Data of Experiment 1 and 2 ####

## read in Data Exp 1
Data1<-read.table("../../1_Experiment1/4_Analysis/DataRatingsExperiment1.txt", header=T)
describe(Data1) # 62 pps - 6 variables - 496 lines of data (8x62)
Data1<-Data1[,-c(2)]
head(Data1)
colnames(Data1)=c("pp", "rating", "fac", "tfac", "cont_corr")

## read in Data Exp 2
Data2<-read.table("../../2_Experiment2/4_Analysis/DataRatingsExperiment2.txt", header=T)
describe(Data2) # 62 pps - 7 variables - 496 lines of data (8x62)
Data2<-Data2[,-c(2,7)]
head(Data2)
colnames(Data2)=c("pp", "rating", "fac", "tfac", "cont_corr")
Data2$pp<-Data2$pp+62

## Add variable Exp indicating which experiment pps participated in: 1 or 2
Data1$Exp<-1
Data2$Exp<-2

## Merge Data files Exp 1 and 2
combData<-rbind(Data1, Data2) 
describe(combData)

##### 2. Prepare Lmer Analyses Explicit Ratings ####

## factorize variables

combData$ppn<-factor(combData$pp)       ## pp nr
combData$fac<-factor(combData$fac)      ## Nr of the face that is used as prime: 0-7
combData$tfac<-factor(combData$tfac)    ## Type face that is used as prime: 1=approached face 2 =avoided face
combData$cont_corr<-factor(combData$cont_corr) ## Contingency Awareness: What action does the participant indicate that this face is used with: 1 = correct (e.g., approached if approached) 2= incorrect (e.g., approached if avoided) 3 = both actions an equal number of times 

##### 3. Perform Lmer Analyses Explicit Ratings ####

## Test effects of fixed factors Face Type and Contingency Awareness

fit1<-lmer(rating~tfac*cont_corr+(1|ppn)+(1|fac), data=combData, contrasts = list(tfac="contr.sum",cont_corr="contr.sum"))
summary(fit1)
Anova(fit1, type='III')

effect('tfac', fit1)           # p=.18: effect of Face Type 
effect('tfac:cont_corr', fit1) # p<.001: Interaction Face Type x Contingency Awareness

## Explore interaction effect of Face Type x COntingency Awareness

# contingency correct:
combData1<-combData[combData$cont_corr==1,] 

fit1_1<-lmer(rating~tfac+(1|pp)+(1|fac), data=combData1, contrasts = list(tfac="contr.sum"))
summary(fit1_1)
Anova(fit1_1, type='III')
effect('tfac', fit1_1)            # p<.001: effect of Face Type

# contingency incorrect:
combData2<-combData[combData$cont_corr==2,]

fit1_2<-lmer(rating~tfac+(1|pp)+(1|fac), data=combData2, contrasts = list(tfac="contr.sum"))
summary(fit1_2)
Anova(fit1_2, type='III')
effect('tfac', fit1_2)           # p=.023: effect of Face Type

# contingency indiscriminate:
combData3<-combData[combData$cont_corr==3,]

fit1_3<-lmer(rating~tfac+(1|pp)+(1|fac), data=combData3, contrasts = list(tfac="contr.sum" ))
summary(fit1_3)
Anova(fit1_3, type='III')
effect('tfac', fit1_3)          # p=.26: effect of Face Type

##### 4. Perform T-test Analyses Explicit Ratings ####

## for contingency correct faces

D1<-combData1[combData1$tfac==1,] # approach face
D2<-aggregate(D1$rating, list(D1$pp), mean)
colnames(D2)=c("ppn", "ap")

D1<-combData1[combData1$tfac==2,] # avoid face
D3<-aggregate(D1$rating, list(D1$pp), mean)
colnames(D3)=c("ppn", "av")

Data4<-merge(D2,D3,by="ppn")
D2<-Data4

t.test(D2$ap,D2$av, paired=T) # approach face rated better than avoid p<.001

D2$a<-D2$ap-D2$av
m1<-mean(D2$a)
s1<-sd(D2$a)
d<-(m1)/(s1)         # effect size d = 0.64

## for contingency incorrect faces

D1<-combData2[combData2$tfac==1,] # approach face
D2<-aggregate(D1$rating, list(D1$pp), mean)
colnames(D2)=c("ppn", "ap")

D1<-combData2[combData2$tfac==2,] # avoid face
D3<-aggregate(D1$rating, list(D1$pp), mean)
colnames(D3)=c("ppn", "av")

Data4<-merge(D2,D3,by="ppn")
D2<-Data4

t.test(D2$ap,D2$av, paired=T) # avoid face rated better than approahc p.003

D2$a<-D2$ap-D2$av
m1<-mean(D2$a)
s1<-sd(D2$a)
d<-(m1)/(s1)              # effect size d = -0.44

## for contingency indiscriminate faces

D1<-combData3[combData3$tfac==1,] # approach face
D2<-aggregate(D1$rating, list(D1$pp), mean)
colnames(D2)=c("ppn", "ap")

D1<-combData3[combData3$tfac==2,] #avoid face
D3<-aggregate(D1$rating, list(D1$pp), mean)
colnames(D3)=c("ppn", "av")

Data4<-merge(D2,D3,by="ppn")
D2<-Data4

t.test(D2$ap,D2$av, paired=T) #p.48

D2$a<-D2$ap-D2$av
m1<-mean(D2$a)
s1<-sd(D2$a)
d<-(m1)/(s1)              # effect size d = -0.10