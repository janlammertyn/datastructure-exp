############### DATA ANALYSES PART 3: Lmer Analyses EPT RTs ##############
## Last update: 17/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)    # package Version 3.17.3
library(reshape)  # package Version 3.17.3
library(lme4)     # package Version 1.1.12
library(car)
library(effects)

##### 1. Read in Derived Data: DataEPT.txt ####

Data<-read.table("../3_DataDerived/DataEPT.txt", header=T)
describe(Data) # 62 pps - 17 variables - 7392 lines of data 

##### 2. Prepare for lmer analyses ####

## create order condition factor: 1=EPT first 2=explicit ratings first

Data$order<-ifelse(Data$ppn%%2==1, 1,2) 

## factorize variables

Data$ppn<-factor(Data$ppn)       ## pp nr
Data$fac<-factor(Data$fac)       ## Nr of the face that is used as prime: 0-7
Data$tfac<-factor(Data$tfac)     ## Type face that is used as prime: 1=approached face 2 =avoided face
Data$ttype<-factor(Data$ttype)   ## Target type: 1 = pos word 0 =neg word
Data$target<-factor(Data$target) ## specific target word that is used: 12 possible words: aangenaam, humeurig,..
Data$order<-factor(Data$order)   ## implicit explicit task order
Data$contingency_correct<-factor(Data$contingency_correct) ## Contingency Awareness: What action does the participant indicate that this face is used with: 1 = correct (e.g., approached if approached) 2= incorrect (e.g., approached if avoided) 3 = don't know 4 = both actions an equal number of times 

## subset data
head(Data)
Data<-Data[-c(2:5,8,10:12,14,16)]

##### 3. Test Lmer Models #####

## Model 1: participant as random factor and fixed factors Target Type and Face TYpe

fit1<-lmer(rt~ttype*tfac + (1|ppn), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.treatment"))
summary(fit1)

## Model 2: MOdel 1 + target as random factor

fit2<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit2)
anova(fit1,fit2) # Model 2 is a better fit

## Model 3: Model 2 + face as random factor

fit3<-lmer(rt~ttype*tfac+(1|ppn)+(1|target)+(1|fac), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit3)
anova(fit2,fit3) # No better fit 

##### 4. Perform Lmer Analyses Overall ####

## Test effects of fixed factors Face Type, Target Type, and Contingency Instruction Condition

fit5<-lmer(rt~ttype*tfac*order+(1|ppn)+(1|target), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum", order="contr.sum"))
summary(fit5)
Anova(fit5, type='III')

effect('ttype', fit5)      # p.030: effect of Target TYpe 
effect('ttype:tfac', fit5) # p.017: Interaction Target Type x Face Type

## Explore main effect of Target Type

Data_p<-Data[Data$ttype==1,] #pos target
mean(Data_p$rt)  # M = 534 ms
sd(Data_p$rt)

Data_n<-Data[Data$ttype==0,] #neg target
mean(Data_n$rt)  # M = 562 ms
sd(Data_n$rt)

## Explore interaction effect of Target Type x Face Type

plot(effect('ttype:tfac', fit5)) 

Data_p<-Data[Data$ttype==1,] # 1. positive

Data_pa<-Data[Data$ttype==1&Data$tfac==1,]  # positive + approach
mean(Data_pa$rt) # M = 531
sd(Data_pa$rt)

Data_pav<-Data[Data$ttype==1&Data$tfac==2,] # positive + avoid
mean(Data_pav$rt) # M = 538
sd(Data_pav$rt)

fit5<-lmer(rt~tfac*order+(1|ppn)+(1|target), data=Data_p, contrasts = list(tfac="contr.treatment", order="contr.sum"))
Anova(fit5, type='III') # Face Type: p.030
fm1W <- confint(fit5)# [-12.97, -0.67]

Data_n<-Data[Data$ttype==0,] # 2. negative

Data_na<-Data[Data$ttype==0&Data$tfac==1,] # negative + approach
mean(Data_na$rt)  # M = 563
sd(Data_na$rt)

Data_nav<-Data[Data$ttype==0&Data$tfac==2,] # negative + avoid
mean(Data_nav$rt) # M = 560
sd(Data_nav$rt)

fit5<-lmer(rt~tfac*order+(1|ppn)+(1|target), data=Data_n, contrasts = list(tfac="contr.treatment", order="contr.sum"))
summary(fit5)
Anova(fit5, type='III') #Face Type: p.18
fm1W <- confint(fit5)# [-2.17, 11.33]

##### 5. Perform Lmer Analyses with contingency Awareness Factor ####

## make contingency awareness factor with 3 levels: correct, incorrect, indiscriminate

Data$contingency_correct<-ifelse(Data$contingency_correct==4,3,Data$contingency_correct)
Data$contingency_correct<-factor(Data$contingency_correct)

## Test effects of fixed factors Face Type, Target Type, Contingency Instruction Condition, and COntingency Awareness

fit6<-lmer(rt~ttype*tfac*order*contingency_correct+(1|ppn)+(1+ttype|target), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum", order="contr.sum", contingency_correct="contr.sum"))
summary(fit6)
Anova(fit6, type='III')

effect('ttype', fit6)                             # p.025: effect of Target TYpe 
effect('ttype:tfac', fit6)                        # p.080: effect Target Typex Face Type
effect('ttype:contingency_correct', fit6)         # p.044: Target Type x Contingency Awareness
effect('ttype:tfac:contingency_correct', fit6)    # p.076: Target Type x Face Type x Contingency Awareness
effect('ttype:tfac:order:contingency_correct', fit6) # p.81: no 4way interaction 

## Explore 3-way interaction of Target Type x Face Type x COntingency Awareness

# 1. contingency correct faces 
Data6.1<-Data[Data$contingency_correct==1, ] 

fit6_1<-lmer(rt~ttype*tfac*order+(1|ppn)+(1|target), data=Data6.1, contrasts = list(ttype="contr.sum", tfac="contr.sum", order="contr.sum"))
summary(fit6_1)                                                                           
Anova(fit6_1, type='III') 
effect('ttype:tfac', fit6_1) # p=.002 Target Type x Face Type 

Data6.1_p<-Data6.1[Data6.1$ttype==1,] # 1.1 : cc + pos

Data6.1_pa<-Data6.1[Data6.1$ttype==1&Data6.1$tfac==1,] # cc + pos + approach
mean(Data6.1_pa$rt) # M = 529
sd(Data6.1_pa$rt)

Data6.1_pav<-Data6.1[Data6.1$ttype==1&Data6.1$tfac==2,] # cc+ pos + avoid
mean(Data6.1_pav$rt) # M = 539
sd(Data6.1_pav$rt)

fit5<-lmer(rt~tfac+(1|ppn)+(1|target), data=Data6.1_p, contrasts = list(tfac="contr.treatment"))
Anova(fit5, type='III') # Face Type p.011
fm1W <- confint(fit5)#[-22.10,-2.82]

Data6.1_n<-Data6.1[Data6.1$ttype==0,] # 1.2. cc + neg

Data6.1_na<-Data6.1[Data6.1$ttype==0&Data6.1$tfac==1,] # cc + neg + approach
mean(Data6.1_na$rt) # M = 561
sd(Data6.1_na$rt)

Data6.1_nav<-Data6.1[Data6.1$ttype==0&Data6.1$tfac==2,] # cc + neg + avoid
mean(Data6.1_nav$rt) # M =551
sd(Data6.1_nav$rt)

fit5<-lmer(rt~tfac+(1|ppn)+(1|target), data=Data6.1_n, contrasts = list(tfac="contr.treatment"))
Anova(fit5, type='III') # # Face Type p.10
fm1W <- confint(fit5)#[-1.66,17.77]

# 2. contingency incorrect faces
Data6.2<-Data[Data$contingency_correct==2, ] 

fit6_2<-lmer(rt~ttype*tfac*order+(1|ppn)+(1|target), data=Data6.2, contrasts = list(ttype="contr.sum", tfac="contr.sum", order="contr.sum"))
summary(fit6_2)
Anova(fit6_2, type='III') 
effect('ttype:tfac', fit6_2)       # p.46 Target Type x Face Type 
effect('ttype:tfac:order', fit6_2) # p.96 Target Type x Face Type x Contingency Instruction

# 3. contingency indiscriminate faces
Data6.3<-Data[Data$contingency_correct==3, ]  

fit6_3<-lmer(rt~ttype*tfac*order+(1|ppn)+(1|target), data=Data6.3, contrasts = list(ttype="contr.sum", tfac="contr.sum", order="contr.sum"))
summary(fit6_3)
Anova(fit6_3, type='III')
effect('ttype:tfac', fit6_3)       # p.65 Target Type x Face Type 
effect('ttype:tfac:order', fit6_3) # p.82 Target Type x Face Type x Contingency Instruction