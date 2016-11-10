# Gan-Song-paymo

## Sturctre of the repo

    ├── README.md 
    ├── run.sh
    ├── src
    │    └── mainfile.cpp
    |    └── set_compare.cpp
    |    └── tree.cpp
    |    └── node.h
    |    └── reader.h
    |    └── set_compare.h
    |    └── tree.h
    ├── paymo_input
    │    └── batch_payment.txt
    |    └── stream_payment.txt
    ├── paymo_output
         └── output1.txt
         └── output2.txt
         └── output3.txt
         └── output3.txt
         └──current_balance_for_all_users.txt
         └──transaction_amount_alert.txt
         
## Sturctre of the repo
Inder to run the code, just run the shell in the current directory `bash run.sh` in Linux UBUNTU 16.10 (where I tested)

## output
the `output1.txt`, `output2.txt`, `output3.txt` are located in paymo_output folder (give outputs for feature 1 2 3 as you required)

## Two New features

Two other features' output `current_balance_for_all_users.txt` and `transaction_amount_alert.txt` are also located in paymo_output folder

### description of the two features: 
First is to calculate the accumulated balance situation. Ex. A user have a transaction history pay 5 and receive 10, receive 20. Then the output for user id A is +25.
Second is to alert if user A make a payment which exceed 10*time max payment in history, if it is the first time to pay, also alert since max payment in history is 0. otherwise not alert                      



