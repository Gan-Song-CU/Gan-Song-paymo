# Gan-Song-paymo

## Sturctre of the repo

    ├── README.md 
    ├── run.sh
    ├── src
    │    └── antifraud.java
    ├── paymo_input
    │    └── batch_payment.txt
    |    └── stream_payment.txt
    ├── paymo_output
    │    └── output1.txt
    |    └── output2.txt
    |    └── output3.txt
    |    └── output3.txt
    |    └──current_balance_for_all_users.txt
    |    └──transaction_amount_alert.txt
         
## Sturctre of the repo
Inder to run the code, just run the shell ./run.sh

## Two New features

two other features output "current_balance_for_all_users.txt" and "transaction_amount_alert.txt" are also located in paymo_output folder

### description of the two features: 
first is to calculate the accumulated balance situation. Ex. A user have a transaction history pay 5 and receive 10, receive 20. Then the output for user id A is +25.
second is to alert if user A make a payment which exceed 10*time max payment in history, if it is the first time to pay, also alert since max payment in history is 0. otherwise not alert                      



