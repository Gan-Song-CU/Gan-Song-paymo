#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include "tree.h"
#include "node.h"
#include"reader.h"
#include"set_compare.h"
using namespace std;




int main(){

	reader batch("./paymo_input/batch_payment.txt");
	reader online("./paymo_input/stream_payment.txt");

	batch.load();                                //load batch file
	online.load();                               //load stream file
	batch.getoff_hearder();
	online.getoff_hearder();


	tree data(nullptr);
	
	int id1 = 0;
	int id2 = 0;
	double money=0.0;
	int jj = 0;


	////////////////////////////////////////////////////////////////////////////
	///////////  read batch file and build tree data structure /////////////////

	cout << "start reading batch file:"<<endl;
	while (batch.readline().size()>0) {

		if (++jj % 100000 == 0){
			cout << jj<< " files have been processed" << endl;
		}

		batch.read_id(id1, id2,money);

		data.insert(id1, id2, money, "pay");
		data.insert(id2, id1, money, "receive");

		if (batch.input.eof()){                          ///check if it goes to the end of line
			break;
		}

	} ;



	///////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////  read online file and make judement on their friendship and output decision ////////////////

	cout << "start tecking stream file:" << endl;

	set_compare compa;
	ofstream output1;
	ofstream output2;
	ofstream output3;
	ofstream output4;
	ofstream output5;
	output1.open("./paymo_output/output1.txt");
	output2.open("./paymo_output/output2.txt");
	output3.open("./paymo_output/output3.txt");
	output4.open("./paymo_output/transaction_amount_alert.txt");
	output5.open("./paymo_output/current_balance_for_all_users.txt");
	jj = 0;


	

	while (online.readline().size() > 0) {

		if (++jj % 10000 == 0){
			cout << jj << " files have been processed" << endl;
		}


		online.read_id(id1, id2, money);

		set<int>*  id1_fri = data.search_fri(id1);        // search friendlist of id1
		set<int>*  id2_fri = data.search_fri(id2);        // search friendlist of id2
		double max_pay = data.search_max_trans(id1);      // search max_payment_transaction of id1


		////////////////////////////////////////////////////

		if (10* max_pay <  money){                     // alert
			output4 << "alert: payment exceed 10 times of your maximum transaction in hisory"<<endl;
		}
        else                                           // no alert
        {
			output4 << "fine: payment within 10 times of your maximum transaction in hisory" << endl;
        }



		
		if (id1 == id2){                                //  check if pay to him/herself

			output1 << "trusted" << endl;
			output2 << "trusted" << endl;
			output3 << "trusted" << endl;
		}

		else{
			/////////////////////////////////////////////////////////

			if (id1_fri->empty() || id2_fri->empty())    // check if one of them has no friends or can not be found in previous batch (new user)
			{
				output1 << "unverified" << endl;
				output2 << "unverified" << endl;
				output3 << "unverified" << endl;
			}


			else {
				if (compa.comp_1_ord(id1_fri, id2)){    // check first order friendship 

					output1 << "trusted" << endl;
					output2 << "trusted" << endl;
					output3 << "trusted" << endl;
				}

				else
				{
					output1 << "unverified" << endl;

					if (compa.comp_2_ord(id1_fri, id2_fri)){   // check second order friendship from two sides
						output2 << "trusted" << endl;
						output3 << "trusted" << endl;

					}

					else{
						output2 << "unverified" << endl;

						if (compa.comp_4_ord(id1_fri, id2_fri, data)){   // check forth order friendship from two sides
							output3 << "trusted" << endl;
						}

						else{
							output3 << "unverified" << endl;
						}

					}



				}
			}
		}


		if (online.input.eof()){          ////check if it go to the end of line
			break;
		}



	}
	

	cout << "start outputing total balance for every user:" << endl;
	data.output_balance(&output5);
	


	output1.close();   // close output
	output2.close();
	output3.close();
	output4.close();
	output5.close();

	cout << " everything finished: freeing memory for tree" << endl;
	

	return 0;
}