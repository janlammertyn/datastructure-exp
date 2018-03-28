#   Folder structure scheme for Experimental Research

In this example we provide best practices for digital file organization within the context of an experimental research project. While the suggested structure can serve as a backbone, there is plenty of room for personal and contextual adaptations which can easily applied. We assume that an experimental research project (e.g. a PhD) typically consists of one or more subprojects (i.e. research lines), and that subprojects consist of one or more experiments.  


# Contents
We provide the following material that you can adapt for your own use: 

- `folder_structure_skeleton.zip`: zip file containing all folders of the structured scheme, as well as a guide. If you want to use the folder scheme yourself, download this file and extract it to the location where you want to place your project. You will then have an empty version of the experimental research folder scheme.
- `PVD_2014_PhD_ContingencyAwareness`:  Folder with an example of real data using the experimental research folder scheme. You can use this as inspiration for how to organize your own data.

# Guide

In this document we provide best practices for digital file organization within the context of an experimental research project. While the suggested structure can serve as a backbone, personal and contextual adaptations should be obvious and easily applied. We assume that the main experimental research project (e.g. a PhD) typically consists of one or more subprojects (i.e. research lines), and that subprojects consist of one or more experiments. In Figure 1, a tree view representation is shown of the folder structure discussed. What follows is a description of the folders, subfolders and their content. 

```
Researcher_YYYY_MainProjectName_SubProjectName/ 
├── 1_Background
│   ├── 1_Literature
│   │   └── Authors_year_title.pdf
│   ├── 2_Documentation
│   ├── 3_EthicsGovernance
│   │   ├── 1_EthicsApproval
│   │   └── 2_ConsentForms
│   └── 4_Reports
├── 2_Experiments
│   ├── 1_Experiment1
│   │   ├── 1_Materials
│   │   ├── 2_DataRaw
│   │   ├── 3_DataDerived
│   │   └── 4_Analysis
│   └── 2_Experiment2
│       ├── 1_Materials
│       ├── 2_DataRaw
│       ├── 3_DataDerived
│       └── 4_Analysis
└── 3_Dissemination
    ├── 1_Publications
    │   ├── 1_Draft
    │   └── 2_Submission
    ├── 2_Presentations
    └── 3_Posters
```
Figure 1 – Tree view of the template folder structure

## Top level folder

The top level folder name describes the main project and subproject conducted. Preferably it contains the researcher's initials, the year of conduction, the main project's name and a subproject identifier. It is good practice to give both the main project and subproject unique and informative names.
Typically for a PhD-student the main project will be the PhD, although side projects can exist.  A main project consists of one or more research lines (subprojects). 

Naming template: `Researcher_YYYY_MainProjectName_SubProjectName/` 

Example: `PVD_2014_PHD_ContingencyAwareness`


## Content subfolders
In experimental research a research line (i.e. subproject) typically consists of one or more experiments which are grouped conceptually. Therefore each subproject folder can have one or more “Experiment” folders. Besides the Experiment folders, background information can be stored in the “Background” folder, and all publicity material is placed in the “Dissemination” folder.

### Background folder
The Background level contains: 
   - Scientific “Literature”, for instance research articles of related studies.
   - All “documentation” that helps to describe the current subproject. For instance data fact sheets, field notes, ...
   - All things related to “Ethics governance”. For instance, application file to the ethics committee. Important: to avoid privacy issues, the consent forms are also stored at this level to separate them from the actual data stored at the Experiment-level.
   - The data management plan

### Experiment folder(s) 
Multiple experiments can be stored within a subproject. To make sure these experiments are sorted in a sensible way, add a sequence tag to the name. This can be a simple number (e.g. Exp01, Exp02,...) or a date if that makes more sense (e.g. Exp_20160605,...). 

The Experiment folder contains the following subfolders: `Materials`, `DataRaw`, `DataDerived`, and `Analysis`.

#### Materials
The materials used to run the experiment. This can be computer programs, experiment code, stimuli, surveys, informed consent template, ... 

#### DataRaw
This folder contains the raw data. This refers to the first registration of what was meant to be measured. We recommend that the raw data is accompanied by adequate documentation (e.g. a codebook describing the variables). Raw data should remain unaltered. To avoid accidental changes to the raw data it is placed in a separate folder from derived data. 

#### DataDerived
The derived data folder contains all data sets which are derivations of the raw data. To explain the transition from raw to derived data it is recommended to provide ample documentation. This also includes documentation describing the relation between different data sets. The documentation can be provided in this folder, either in a separate document or by means of annotated data processing scripts.

#### Analysis
The analysis folder contains all data analysis plans, scripts and output files. Also the documentation explaining analysis design, choices and set-up can be stored here (either in a separate document or by means of annotated data analysis scripts). 

### Dissemination folder
The dissemination folder contains publications, presentations, posters and other publicity material.




