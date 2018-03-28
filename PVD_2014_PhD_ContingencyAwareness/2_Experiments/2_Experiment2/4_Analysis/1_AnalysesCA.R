############### DATA ANALYSES PART 1: Contingency Awareness ##############
## Last update: 10/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)

##### 1. Read in Derived Data: DataAggregated.txt ####

Data<-read.table("../3_DataDerived/DataAggregated.txt", header=T)
describe(Data) # 62 pps - 107 variables - 62 lines of data (1 /pp)

##### 2. Perform between-groups t-tests ####

## compare nr of correct faces for the two order conditions
# subset data: participants who first did IAT
Data_1<-Data[Data$orde==1,] 
mean(Data_1$cc) # 3.47/8 correct
sd(Data_1$cc)
mean(Data_1$cc_p) # 43% correct
sd(Data_1$cc_p)

# subset data: pps who first did explicit rating task
Data_2<-Data[Data$orde==2,] 
mean(Data_2$cc) # 4.47/8 correct
sd(Data_2$cc)
mean(Data_2$cc_p) # 56% correct
sd(Data_2$cc_p)

t.test(Data_1$cc_p, Data_2$cc_p) # t(60) = -1.85, p=.069: more correct if start with explicit ratings

##### 3. Means overall ####

## nr of correct and incorrect faces:

mean(Data$cc_p) #49% correct
sd(Data$cc_p)

mean(Data$ci_p) # 19% incorrect
sd(Data$ci_p)

t.test(Data$cc, Data$ci, paired=TRUE) # more correct than incorrect! p<.001

## nr of correct and incorrect faces:
mean(Data$dbt_p) # 9% don't know
sd(Data$dbt_p)

mean(Data$dbt2_p) # 22% both actions equal
sd(Data$dbt2_p)
