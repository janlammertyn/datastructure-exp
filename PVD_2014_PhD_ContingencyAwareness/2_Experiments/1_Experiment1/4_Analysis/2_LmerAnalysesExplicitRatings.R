############### DATA ANALYSES PART 2: Lmer Analyses Explicit Ratings ##############
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

##### 1. Read in Derived Data: DataAggregated.txt ####

Data<-read.table("../3_DataDerived/DataAggregated.txt", header=T)
describe(Data) # 62 pps - 105 variables - 62 lines of data 

##### 2. Prepare for lmer analyses ####

# reshape data to long format

Data_wide<-Data[c(1, 2, 4, 12, 20, 28,36,44,52,60,84:91,92:99)] 
Data_long<-melt(Data_wide, id.var=c("pp", "ca","X0ty", "X1ty", "X2ty", "X3ty", "X4ty", "X5ty", "X6ty", "X7ty", "f1_cc", "f2_cc", "f3_cc", "f4_cc", "f5_cc", "f6_cc", "f7_cc", "f8_cc"), variable_name="variable")
head(Data_long)

# compute face variable: which face 1-8

Data_long$face<-Data_long$variable
Data_long$face<-ifelse(Data_long$face=="f1_exp", 1, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f2_exp", 2, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f3_exp", 3, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f4_exp", 4, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f5_exp", 5, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f6_exp", 6, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f7_exp", 7, Data_long$face)
Data_long$face<-ifelse(Data_long$face=="f8_exp", 8, Data_long$face)

# compute Face Type variable: 1 = approached face , 2 = avoided face

Data_long$type<-ifelse(Data_long$variable=="f1_exp", Data_long$X0ty, Data_long$variable)
Data_long$type<-ifelse(Data_long$variable=="f2_exp", Data_long$X1ty, Data_long$type)
Data_long$type<-ifelse(Data_long$variable=="f3_exp", Data_long$X2ty, Data_long$type)
Data_long$type<-ifelse(Data_long$variable=="f4_exp", Data_long$X3ty, Data_long$type)
Data_long$type<-ifelse(Data_long$variable=="f5_exp", Data_long$X4ty, Data_long$type)
Data_long$type<-ifelse(Data_long$variable=="f6_exp", Data_long$X5ty, Data_long$type)
Data_long$type<-ifelse(Data_long$variable=="f7_exp", Data_long$X6ty, Data_long$type)
Data_long$type<-ifelse(Data_long$variable=="f8_exp", Data_long$X7ty, Data_long$type)

# compute Contingency Awareness variable: 1 = correct , 2 = incorrect, 3=indiscriminate

Data_long$cc<-ifelse(Data_long$variable=="f1_exp", Data_long$f1_cc, Data_long$variable)
Data_long$cc<-ifelse(Data_long$variable=="f2_exp", Data_long$f2_cc, Data_long$cc)
Data_long$cc<-ifelse(Data_long$variable=="f3_exp", Data_long$f3_cc, Data_long$cc)
Data_long$cc<-ifelse(Data_long$variable=="f4_exp", Data_long$f4_cc, Data_long$cc)
Data_long$cc<-ifelse(Data_long$variable=="f5_exp", Data_long$f5_cc, Data_long$cc)
Data_long$cc<-ifelse(Data_long$variable=="f6_exp", Data_long$f6_cc, Data_long$cc)
Data_long$cc<-ifelse(Data_long$variable=="f7_exp", Data_long$f7_cc, Data_long$cc)
Data_long$cc<-ifelse(Data_long$variable=="f8_exp", Data_long$f8_cc, Data_long$cc)

Data_long<-Data_long[c(1, 2,20:23)] 

# factorize variables

Data_long$pp<-factor(Data_long$pp)     ## participant
Data_long$face<-factor(Data_long$face) ## Nr of the face : 1-8
Data_long$type<-factor(Data_long$type) ## Type face: 1=approached, 2=avoided
Data_long$cc<-factor(Data_long$cc)     ## Contingency correct: 1= yes, 2= no, 3=doubt
Data_long$ca<-factor(Data_long$ca)     ## condition of participant: 0=no cont instrs

##### 3. Test Lmer Models ####

# Model 1: only random effect of participant and fixed effect of face type

fit1<-lmer(value~type+(1|pp), data=Data_long, contrasts = "contr.sum")
summary(fit1) 

# Model 2: Model 1 + random effect of face

fit2<-lmer(value~type+(1|pp)+(1|face), data=Data_long, contrasts = list(type="contr.sum"))
summary(fit2)
anova(fit1,fit2) # Model 2 is a better fit

# Model 3: Model 2 + random slope of type

fit3<-lmer(value~type+(1|pp)+(1+type|face), data=Data_long, contrasts = list(type="contr.sum"))
summary(fit3)

anova(fit2,fit3) # No better fit 

##### 4. Perform Lmer Analyses Overall ####

# Test effects of fixed factors Type and Contingency Instruction Condition

fit<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long, contrasts = list(type="contr.sum", ca="contr.sum"))
summary(fit)
Anova(fit, type='III')

effect('type', fit)    # p<.001:  significant effect of face type
effect('type:ca', fit) # p.98:    no signficant interaction

# Explore main effect of Face Type

Data_long_a<-Data_long[Data_long$type==1,] # approached
mean(Data_long_a$value)  # M = 4.03
sd(Data_long_a$value)

Data_long_av<-Data_long[Data_long$type==2,] #avoided
mean(Data_long_av$value) # M= 3.68
sd(Data_long_av$value)

fit5<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long, contrasts = list(type="contr.treatment", ca="contr.sum"))
fm1W <- confint(fit5)# [0.17, 0.55] # confidence intervals

##### 5. Perform Lmer Analyses with contingency Awareness Factor ####

# Test effects of fixed factors Type, Contingency Instruction Condition and Contingency Awareness

fit6<-lmer(value~type*ca*cc+(1|pp)+(1|face), data=Data_long, contrasts = list(type="contr.sum", ca="contr.sum",cc="contr.sum" ))
summary(fit6)
Anova(fit6, type='III')

effect('type', fit6)    # p.76: no significant effect face type 
effect('type:cc', fit6) # p<.001: significant interaction effect Face Type x Contingency Awareness

# Explore interaction effect of face type x contingency awareness:

Data_long.1<-Data_long[Data_long$cc==1, ] # contingency correct faces: 
fit6.1<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long.1, contrasts = list(type="contr.sum", ca="contr.sum" ))
summary(fit6.1)                                                            
Anova(fit6.1, type='III')
effect('type', fit6.1) # face type effect is significant: <.001
plot(effect('type', fit6.1))
Data_long.1_a<-Data_long.1[Data_long.1$type==1,] #approached
mean(Data_long.1_a$value) #4.26
sd(Data_long.1_a$value)
Data_long.1_av<-Data_long.1[Data_long.1$type==2,] #avoided
mean(Data_long.1_av$value) #3.47
sd(Data_long.1_av$value)
fit6.1<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long.1, contrasts = list(type="contr.treatment", ca="contr.sum" ))
fm1W <- confint(fit6.1, method="Wald")# [0.40, 0.90]
 
Data_long.2<-Data_long[Data_long$cc==2, ] # contingency incorrect faces: 
fit6.2<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long.2, contrasts = list(type="contr.sum", ca="contr.sum" ))
summary(fit6.2)                                                            
Anova(fit6.2, type='III')
effect('type', fit6.2) # face type effect is marg significant .057
plot(effect('type', fit6.2))
Data_long.2_a<-Data_long.2[Data_long.2$type==1,] #approached
mean(Data_long.2_a$value) #3.35
sd(Data_long.2_a$value)
Data_long.2_av<-Data_long.2[Data_long.2$type==2,] #avoided
mean(Data_long.2_av$value) #4.16
sd(Data_long.2_av$value)
fit6.2<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long.2, contrasts = list(type="contr.treatment", ca="contr.sum" ))
fm1W <- confint(fit6.2)# [-0.81, 0.01]

Data_long.3<-Data_long[Data_long$cc==3, ] # contingency indiscriminate faces:
fit6.3<-lmer(value~type*ca+(1|pp)+(1|face), data=Data_long.3, contrasts = list(type="contr.sum", ca="contr.sum" ))
summary(fit6.3)                                                            
Anova(fit6.3, type='III')
effect('type', fit6.3) # face type effect is not significant .54
plot(effect('type', fit6.3))
Data_long.3_a<-Data_long.3[Data_long.3$type==1,] #approached
mean(Data_long.3_a$value) #3.89
sd(Data_long.3_a$value)
Data_long.3_av<-Data_long.3[Data_long.3$type==2,]#avoided
mean(Data_long.3_av$value) #4.03
sd(Data_long.3_av$value)

##### 3. write away final data file #######

write.table(Data_long, "DataRatingsExperiment1.txt", sep="\t") 
# file saved to perform analyses on data of both experiments