############### DATA ANALYSES PART 1: Contingency Awareness ##############
## Last update: 10/09/2016 ##
## Author: Pieter Van Dessel ##
## Made in: RStudio Version 0.98.1103 ##
## R version 3.2.5 (2016-04-14) ##

##### Load libraries ####
library(Hmisc)

##### 1. Read in Derived Data: DataAggregated.txt ####

Data<-read.table("../3_DataDerived/DataAggregated.txt", header=T)
describe(Data) # 62 pps - 105 variables - 62 lines of data (1 /pp)

##### 2. Perform between-groups t-tests ####

# compare nr of correct faces for the two contingency instruction conditions

Data_1<-Data[Data$ca==1,] # subset data: participants with contingency instructions
mean(Data_1$cc) # 6.16/8 correct
sd(Data_1$cc)
mean(Data_1$cc_p) # 77% correct
sd(Data_1$cc_p)

Data_2<-Data[Data$ca==0,] # subset data: pps with no contingency instructions
mean(Data_2$cc) # 4.35/8 correct
sd(Data_2$cc)
mean(Data_2$cc_p) # 54% correct
sd(Data_2$cc_p)

t.test(Data_1$cc_p, Data_2$cc_p) # t(60) = 3.34, p=.001: more correct if instrs

# compare nr of incorrect faces for the two contingency instruction conditions

mean(Data_1$ci) # 1.23/8 incorrect
sd(Data_1$ci)
mean(Data_1$ci_p) # 15% incorrect
sd(Data_1$ci_p)

mean(Data_2$ci) # 1.58/8 incorrect
sd(Data_2$ci)
mean(Data_2$ci_p) # 20% incorrect
sd(Data_2$ci_p)

t.test(Data_1$ci, Data_2$ci) # t(60) = -0.91, p = .37: no effect

t.test(Data_1$cc, Data_1$ci, paired=TRUE) # p<.001: Group 1 more correct than incorrect
t.test(Data_2$cc, Data_2$ci, paired=TRUE) # p<.001: Group 2 more correct than incorrect

# compare nr of indiscriminate faces for two contingency instruction conditions

mean(Data_1$dbt) # 0.61/8 indiscriminate
sd(Data_1$dbt)
mean(Data_1$dbt_p) # 8% indiscriminate
sd(Data_1$dbt_p)

mean(Data_2$dbt) # 2.06/8 indiscriminate
sd(Data_2$dbt)
mean(Data_2$dbt_p) # 26% indiscriminate
sd(Data_2$dbt_p)

t.test(Data_1$dbt, Data_2$dbt) # t(60) = -3.44, p=.001: less indiscriminate if instrs