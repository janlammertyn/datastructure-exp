Data Analysis

LAST UPDATED: 10/09/2016
BY: Pieter Van Dessel

1. In RStudio: Run script 1_DataCleaningEvaluativePrimingTask

   --> This will open /2_DataRaw/primedata.rtd
   --> This will get rid of data from pps>2.5sds over mean error  (pp19)  
       + get rid of data  for which errors were made or rts > or <2.5sds deviated from participants' mean
   --> New priming data saved as DataEPT.txt

2. In RStudio: Run script 2_PreparationAggregatedFile

   --> This will open /2_DataRaw/explicitdata.rtd
   --> Variables will be created: contingency_correct (1 = correct /2 = incorrect /3 = indiscriminate)
   --> New aggregated data file saved as DataAggregated.txt


