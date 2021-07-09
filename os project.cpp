#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void menu(){
	cout<<"========================================================"<<endl;
	cout<<"Hospital Wards Management System"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"[1] Resources are enough, First-fit allocation method"<<endl;
	cout<<"[2] Resources are not enough, Best-fit allocation method"<<endl;
	cout<<"[3] Exit"<<endl;
	cout<<"Your choice: ";
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the block allocated to a
    // process
    int allocation[n];
  
    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));
  
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
  
        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;
  
            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];
        }
    }
  
    cout << "\nPatients No.\tPatients Health\t   Ward no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t       " << processSize[i] << "\t\t   ";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
  

	int main(){
		int choice = 0;
		
		while(choice != 3){
			
			menu();
			cin>>choice;
			
			if(choice == 1){
				
				int patientNo, wardNo, flags[100], allocation[100];
				
				for(int i=0; i<100; i++){
					flags[i] = 0;
					allocation[i] = -1;
				}
				
				cout<<"\n\nEnter the number of patients: ";
				cin>>patientNo;
				int patientHealth[patientNo];
				
				cout<<"\n Based on the health condition lists: "<<endl;
				cout<<"1) Good"<<endl;
				cout<<"2) Mild"<<endl;
				cout<<"3) Critical"<<endl;
				cout<<"\nEnter the health condition of each patients: \n";
				for(int i=0; i<patientNo; i++){
					
					cout<< "Patient " << i+1 << ": " ;
					cin>>patientHealth[i];
				}
				
				cout<<"\nEnter the number of wards: ";
				cin >> wardNo;
				int wardType[wardNo];
				
				cout<<"\n Based on the wards type lists: "<<endl;
				cout<<"1) Normal"<<endl;
				cout<<"2) Mild"<<endl;
				cout<<"3) ICU"<<endl;
				cout<<"\nEnter the wards type : \n";
				for(int i=0; i<wardNo; i++){
					cout<< "ward " << i+1 <<": ";
					cin>>wardType[i];
				}
				
				for(int i=0; i<patientNo; i++)
				for(int j=0; j<wardNo; j++)
				
				if(flags[j] == 0 && wardType[j] >= patientHealth[i])
				
				{
					allocation[j] = i;
					flags[j] = 1;
					break;
				}
				
			     cout<<"\nWard no.\ttype\t\tPatient no.\t\tHealth";
		
		          for(int i = 0; i < wardNo; i++){
		
		
		          cout<<"\n   "<< i+1<<"\t\t "<<wardType[i]<<"\t\t";
		
		
		          if(flags[i] == 1)
		
		
		
		          cout<<allocation[i]+1<<"\t\t\t   "<<patientHealth[allocation[i]];
		
		          else
		
		          cout<<"Not allocated";
				  
		}
					cout <<endl;
					system("Pause");
					system("CLS");
					}
			else if (choice == 2){
				int wardNo, patientNo;
	
				cout<<"\n\nEnter the number of wards: ";
				cin>>wardNo;
				int wardType[wardNo];
				
					cout<<"\n Based on he wards type lists: "<<endl;
					cout<<"1) Normal"<<endl;
					cout<<"2) Mild"<<endl;
					cout<<"3) ICU"<<endl;
					cout<<"\nEnter the wards type : \n";
				for(int i=0; i<wardNo; i++){
					cout<< "ward " << i+1 <<": ";
					cin>>wardType[i];
				}
				
				cout<<"\nEnter the number of patients: ";
				cin>>patientNo;
				int patientHealth[patientNo];
				
					cout<<"\n Based on the health condition lists: "<<endl;
					cout<<"1) Good"<<endl;
					cout<<"2) Mild"<<endl;
					cout<<"3) Critical"<<endl;
					cout<<"\nEnter the health condition of each patients:\n ";
				for(int i=0; i<patientNo; i++){
					cout<< "Patient " << i+1 << ": " ;
					cin>>patientHealth[i];
				}
				
				
			    
			    int m = sizeof(wardType)/sizeof(wardType[0]);
			    int n = sizeof(patientHealth)/sizeof(patientHealth[0]);
			  
			    bestFit(wardType, m, patientHealth, n);
			    system("Pause");
				system("CLS");
						}
			else
				cout << "Thank you for using the system";
					}
		


return 0;

} 
		
		
		
		
		
		
		
		
		
	

