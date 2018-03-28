############### DATA ANALYSES PART 3: Lmer Analyses EPT RTs ##############
## Last update: 10/09/2016 ##
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
describe(Data) # 62 pps - 17 variables - 7340 lines of data 

##### 2. Prepare for lmer analyses ####

# create contingency instructions condition factor: 1=instrs 0=no instrs

Data$ca<-ifelse(Data$ppn%%2==1, 1,0) 

# factorize variables

Data$ppn<-factor(Data$ppn)       ## pp nr
Data$fac<-factor(Data$fac)       ## Nr of the face that is used as prime: 0-7
Data$tfac<-factor(Data$tfac)     ## Type face that is used as prime: 1=approached face 2 =avoided face
Data$ttype<-factor(Data$ttype)   ## Target type: 1 = pos word 0 =neg word
Data$target<-factor(Data$target) ## specific target word that is used: 12 possible words: aangenaam, humeurig,..
Data$ca<-factor(Data$ca)         ## cont instructions
Data$contingency_correct<-factor(Data$contingency_correct) ## Contingency Awareness: What action does the participant indicate that this face is used with: 1 = correct (e.g., approached if approached) 2= incorrect (e.g., approached if avoided) 3 = both actions an equal number of times 

# subset data
Data<-Data[-c(2:5,8,10:12,14,16)]

##### 3. Test Lmer Models #####

# Model 1: participant as random factor and fixed factors Target Type and Face TYpe

fit1<-lmer(rt~ttype*tfac + (1|ppn), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.treatment"))
summary(fit1)

# Model 2: MOdel 1 + target as random factor

fit2<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit2)
anova(fit1,fit2) # Model 2 is a better fit

# Model 3: Model 2 + face as random factor

fit3<-lmer(rt~ttype*tfac+(1|ppn)+(1|target)+(1|fac), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
summary(fit3)
anova(fit2,fit3) # No better fit 

##### 4. Perform Lmer Analyses Overall ####

# Test effects of fixed factors Face Type, Target Type, and Contingency Instruction Condition

fit5<-lmer(rt~ttype*tfac*ca+(1|ppn)+(1|target), data=Data, contrasts = "contr.sum")
summary(fit5)
Anova(fit5, type='III')

effect('ttype', fit5)      # p.009: effect of Target TYpe 
effect('ttype:tfac', fit5) # p.057: Interaction Target Type x Face Type

# Explore main effect of Target Type

Data_p<-Data[Data$ttype==1,] #pos target
mean(Data_p$rt)  # M = 560 ms
sd(Data_p$rt)

Data_n<-Data[Data$ttype==0,] #neg target
mean(Data_n$rt)  # M = 587 ms
sd(Data_n$rt)

# Explore interaction effect of Target Type x Face Type

plot(effect('ttype:tfac', fit5)) 

Data_p<-Data[Data$ttype==1,] # 1. positive

Data_pa<-Data[Data$ttype==1&Data$tfac==1,]  # positive + approach
mean(Data_pa$rt) # M = 556
sd(Data_pa$rt)

Data_pav<-Data[Data$ttype==1&Data$tfac==2,] # positive + avoid
mean(Data_pav$rt) # M = 563
sd(Data_pav$rt)

fit5<-lmer(rt~tfac*ca+(1|ppn)+(1|target), data=Data_p, contrasts = list(tfac="contr.treatment", ca="contr.sum"))
Anova(fit5, type='III') # Face Type: p.067
fm1W <- confint(fit5)# [-14.16, 0.47]

Data_n<-Data[Data$ttype==0,] # 2. negative

Data_na<-Data[Data$ttype==0&Data$tfac==1,] # negative + approach
mean(Data_na$rt)  # M = 593
sd(Data_na$rt)

Data_nav<-Data[Data$ttype==0&Data$tfac==2,] # negative + avoid
mean(Data_nav$rt) # M = 582
sd(Data_nav$rt)

fit5<-lmer(rt~tfac*ca+(1|ppn)+(1|target), data=Data_n, contrasts = list(tfac="contr.treatment", ca="contr.sum"))
summary(fit5)
Anova(fit5, type='III') #Face Type: p.020
fm1W <- confint(fit5)# [1.48, 17.37]

##### 5. Perform Lmer Analyses with contingency Awareness Factor ####

# Test effects of fixed factors Face Type, Target Type, Contingency Instruction Condition, and COntingency Awareness

fit6<-lmer(rt~ttype*tfac*ca*contingency_correct+(1|ppn)+(1+ttype|target), data=Data, contrasts = list(ttype="contr.sum", tfac="contr.sum", ca="contr.sum", contingency_correct="contr.sum"))
summary(fit6)
Anova(fit6, type='III')

effect('ttype', fit6)                            # p.023: effect of Target TYpe 
effect('ttype:tfac', fit6)                        # p.18: effect Target Typex Face Type
effect('ttype:tfac:contingency_correct', fit6)    # p.016 Target Type x Face Type x Contingency Awareness
effect('ttype:tfac:ca:contingency_correct', fit6) # p.004: 4way interaction 

# Explore 3-way interaction of Target Type x Face Type x COntingenyc Awareness

Data6.1<-Data[Data$contingency_correct==1, ] # 1. contingency correct faces 

fit6_1<-lmer(rt~ttype*tfac*ca+(1|ppn)+(1|target), data=Data6.1, contrasts = list(ttype="contr.sum", tfac="contr.sum", ca="contr.sum"))
summary(fit6_1)                                                                           
Anova(fit6_1, type='III') 
effect('ttype:tfac', fit6_1) # p<.001 Target Type x Face Type 

Data6.1_p<-Data6.1[Data6.1$ttype==1,] # 1.1 : cc + pos

Data6.1_pa<-Data6.1[Data6.1$ttype==1&Data6.1$tfac==1,] # cc + pos + approach
mean(Data6.1_pa$rt) # M = 546
sd(Data6.1_pa$rt)

Data6.1_pav<-Data6.1[Data6.1$ttype==1&Data6.1$tfac==2,] # cc+ pos + avoid
mean(Data6.1_pav$rt) # M = 554
sd(Data6.1_pav$rt)

fit5<-lmer(rt~tfac+(1|ppn)+(1|target), data=Data6.1_p, contrasts = list(tfac="contr.treatment"))
Anova(fit5, type='III') # Face Type p.033
fm1W <- confint(fit5)#[-17.99,-0.74]

Data6.1_n<-Data6.1[Data6.1$ttype==0,] # 1.2. cc + neg

Data6.1_na<-Data6.1[Data6.1$ttype==0&Data6.1$tfac==1,] # cc + neg + approach
mean(Data6.1_na$rt) # M = 586
sd(Data6.1_na$rt)

Data6.1_nav<-Data6.1[Data6.1$ttype==0&Data6.1$tfac==2,] # cc + neg + avoid
mean(Data6.1_nav$rt) # M =569
sd(Data6.1_nav$rt)

fit5<-lmer(rt~tfac+(1|ppn)+(1|target), data=Data6.1_n, contrasts = list(tfac="contr.treatment"))
Anova(fit5, type='III') # # Face Type p.031
fm1W <- confint(fit5)#[0.96,20.39]

Data6.2<-Data[Data$contingency_correct==2, ] # 2. contingency incorrect

fit6_2<-lmer(rt~ttype*tfac*ca+(1|ppn)+(1|target), data=Data6.2, contrasts = list(ttype="contr.sum", tfac="contr.sum", ca="contr.sum"))
summary(fit6_2)
Anova(fit6_2, type='III') 
effect('ttype:tfac', fit6_2)    # p.19 Target Type x Face Type 
effect('ttype:tfac:ca', fit6_2) # p.008 Target Type x Face Type x Contingency Instruction

Data6.2_pa<-Data6.2[Data6.2$ttype==1&Data6.2$tfac==1,] # ci + pos + approach
mean(Data6.2_pa$rt)  # M = 581
sd(Data6.2_pa$rt)

Data6.2_pav<-Data6.2[Data6.2$ttype==1&Data6.2$tfac==2,] # ci + pos + avoid
mean(Data6.2_pav$rt) # M = 587
sd(Data6.2_pav$rt)

Data6.2_na<-Data6.2[Data6.2$ttype==0&Data6.2$tfac==1,] # ci + neg + approach
mean(Data6.2_na$rt)  # M = 588
sd(Data6.2_na$rt)

Data6.2_nav<-Data6.2[Data6.2$ttype==0&Data6.2$tfac==2,] # ci + neg + avoid
mean(Data6.2_nav$rt) # M = 606
sd(Data6.2_nav$rt)

Data6.3<-Data[Data$contingency_correct==3, ] # 3. cont indiscriminate faces: 

fit6_3<-lmer(rt~ttype*tfac*ca+(1|ppn)+(1|target), data=Data6.3, contrasts = list(ttype="contr.sum", tfac="contr.sum", ca="contr.sum"))
summary(fit6_3)
Anova(fit6_3, type='III')
effect('ttype:tfac', fit6_3) # p.16 Target Type x Face Type 

Data6.3_pa<-Data6.3[Data6.3$ttype==1&Data6.3$tfac==1,] # cin + pos + approach
mean(Data6.3_pa$rt) # M = 568
sd(Data6.3_pa$rt)

Data6.3_pav<-Data6.3[Data6.3$ttype==1&Data6.3$tfac==2,] # cin + pos + avoid
mean(Data6.3_pav$rt) # M = 576
sd(Data6.3_pav$rt)

Data6.3_na<-Data6.3[Data6.3$ttype==0&Data6.3$tfac==1,]  # cin + neg + approach
mean(Data6.3_na$rt) # M = 619
sd(Data6.3_na$rt)

Data6.3_nav<-Data6.3[Data6.3$ttype==0&Data6.3$tfac==2,] # cin + neg + avoid
mean(Data6.3_nav$rt) # M = 609
sd(Data6.3_nav$rt)

# Explore 4-way interaction of Target Type x Face Type x Contingenyc Awareness x COntingency Instruction

Data6.2_c<-Data6.2[Data6.2$ca==1, ]  # 1. contingency instructions + cont incorrect

fit6.2_c<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=Data6.2_c, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
Anova(fit6.2_c, type='III') # p.019 Target Type x Type of Face

Data6.2_cp<-Data6.2_c[Data6.2_c$ttype==1,] # 1.1. contingency instructions + cont incorrect + pos 

Data6.2_c_pa<-Data6.2_c[Data6.2_c$ttype==1&Data6.2_c$tfac==1,]  # ca1 + ci + pos + approach
mean(Data6.2_c_pa$rt)  # M = 620
sd(Data6.2_c_pa$rt)

Data6.2_c_pav<-Data6.2_c[Data6.2_c$ttype==1&Data6.2_c$tfac==2,] # ca1 + ci + pos + avoid
mean(Data6.2_c_pav$rt) # M = 629
sd(Data6.2_c_pav$rt)

fit6.2_c<-lmer(rt~tfac+(1|ppn)+(1|target), data=Data6.2_cp, contrasts = list(tfac="contr.treatment"))
Anova(fit6.2_c, type='III') # p.36 Type of Face
fm1W <- confint(fit6.2_c)   # [-58.41,21.84]

Data6.2_cp<-Data6.2_c[Data6.2_c$ttype==0,] # 1.2. contingency instructions + cont incorrect + pos 

Data6.2_c_na<-Data6.2_c[Data6.2_c$ttype==0&Data6.2_c$tfac==1,]  # ca1 + ci + neg + approach
mean(Data6.2_c_na$rt)  # M =614
sd(Data6.2_c_na$rt)

Data6.2_c_nav<-Data6.2_c[Data6.2_c$ttype==0&Data6.2_c$tfac==2,] # ca1 + ci + neg + avoid
mean(Data6.2_c_nav$rt) # M = 671
sd(Data6.2_c_nav$rt)

fit6.2_c<-lmer(rt~tfac+(1|ppn)+(1|target), data=Data6.2_cp, contrasts = list(tfac="contr.treatment"))
Anova(fit6.2_c, type='III')# p=.029
fm1W <- confint(fit6.2_c)# [-82.70, -7.34] 

Data6.2_ic<-Data6.2[Data6.2$ca==0, ] # 2. no contingency instructions + cont incorrect

fit6.2_ic<-lmer(rt~ttype*tfac+(1|ppn)+(1|target), data=Data6.2_ic, contrasts = list(ttype="contr.sum", tfac="contr.sum"))
Anova(fit6.2_ic, type='III') # p.20 Target Type x Type of Face