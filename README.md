# Municipal Financial Management System (MFMS) - Project A

Course: PAP521S - Programming in Practice
Language: C
Members: Muzumi Matali - 226136418
         Laoletu Haiduwa - 225034603
         John Shikongo - 225046342
         Daven Muntande - 224035339

## Description
A menu-driven console application that manages municipal employees,
departmental budgets, suppliers and assets, and produces summary reports.

## Features
- Employee management: add, display (recursively), search, sort by salary
  (bubble sort), payslip with tax brackets
- Budget management: allocate budgets, record expenditure, detect overspending
  (calculateBudget: revenue - expenditure)
- Supplier management: add, display, search by name or town, email validation,
  supplier description built with strcpy()/strcat()
- Asset management: add, display, search municipal assets
- Reports: employee, budget, supplier and asset reports
  (highest/lowest initialised from first element per Week 5 notes)
- Input validation throughout: fgets + strcspn, do-while re-prompting,
  no negative salaries/budgets, invalid menu choices handled

## Compile
    gcc -std=c99 -Wall -o mfms main.c utils.c employees.c budget.c suppliers.c assets.c reports.c

## Run
    ./mfms

## Individual Responsibilities
We wrote the codes and tested them together, each of us contributing and assisting to the development of the codes; though the commits were based on who assisted the most and finalised in regards to that particular module.

Commits:

.c files:
  Main.c: Muzumi Matali - 226136418
  Assets.c: John Shikongo - 225046342
  Utils.c: Daven Muntande - 224035339
  Reports.c: Daven Muntande - 224035339
  Suppliers.c: John Shikongo - 225046342
  Employees.c: John Shikongo - 225046342
  Budgets.c: Daven Muntande - 224035339

.h files:
  Assets.h: Laoletu Haiduwa - 225034603
  Utils.h: Laoletu Haiduwa - 225034603
  Reports.h: Muzumi Matali - 226136418
  Suppliers.h: Muzumi Matali - 226136418
  Employees.h: John Shikongo - 225046342
  Budgets.h: Laoletu Haiduwa - 225034603

ReadME file: Muzumi Matali - 226136418
