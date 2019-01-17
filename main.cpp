/* bonus project move 2 nodes*/

#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    string name ;
    int weight = 0;
    int open;
    int close;
    int distance = 0;
    int idx = 0;
    bool visited = false;
};
Node **Matrix;

void createMatrix(int num);
int travllingSalesmanProblem( int s , int V);
int main()
{

    //char inftmp[30] = "/floor.data";
    //char inf[30];
    //strcpy(inf,argv[1]);
    //strcat(inf,inftmp);
    //ifstream file;
	//file.open(inf);

	ifstream file;
    file.open("tp1.data");


    //char oftmp[30] = "/final.path";
    //char of[30];
    //strcpy(of,argv[1]);
    //strcat(of,oftmp);
    //ofstream outfile;
    //outfile.open(of);

    ofstream outfile;
    outfile.open("ans1.txt");


    if(!file){
    	cout<<"fail to open"<<"\n";
	}
	else {
        int nodes_num;
        int edges_num;
        int total_time;
        int start_time;
        file>>nodes_num;
        file>>edges_num;
        file>>total_time;
        file>>start_time;
        createMatrix(nodes_num);
        for(int i=0 ; i<nodes_num ; i++){

            file>>Matrix[i][i].name;
            file>>Matrix[i][i].weight;
            file>>Matrix[i][i].open;
            file>>Matrix[i][i].close;
            Matrix[i][i].idx = i;
        }


        for(int i=0 ; i<edges_num ; i++){
            cout<<i<<endl;
            string first_name;
            string second_name;
            int first_idx = 0;
            int sec_idx = 0;
            file>>first_name;
            file>>second_name;

            for(int k = 0; k < nodes_num ; k++){
                if(Matrix[k][k].name == first_name ){
                    first_idx = Matrix[k][k].idx;
                }
                else if(Matrix[k][k].name == second_name ){
                    sec_idx = Matrix[k][k].idx;
                }
            }
            //cout << first_idx << " " << sec_idx<< endl;
            file>>Matrix[first_idx][sec_idx].distance;
            Matrix[sec_idx][first_idx].distance = Matrix[first_idx][sec_idx].distance;



        }


        int maxHappiness = 0;
        Node firstNode ;
        for(int i=0;i<nodes_num ; i++){
            if(Matrix[i][i].weight>=maxHappiness){
                maxHappiness = Matrix[i][i].weight;
                firstNode = Matrix[i][i];
            }
        }
        int maxHappiness2 = 0;
        int dis = 0;
        Node secondNode ;
        for(int i =0;i<nodes_num;i++){
            if(Matrix[i][i].weight>=maxHappiness2){
                if(Matrix[i][i].idx!=firstNode.idx && Matrix[i][firstNode.idx].distance!=0){
                    if(total_time>= 2* Matrix[i][firstNode.idx].distance)
                    maxHappiness2 = Matrix[i][i].weight;
                    secondNode = Matrix[i][i];
                    dis = Matrix[i][firstNode.idx].distance;
                }

            }
        }
        cout<<firstNode.weight+secondNode.weight<<" "<< 2*dis<<endl;

        int cur_time = start_time;
        cout<<firstNode.name << " " <<cur_time << " " << cur_time<<endl;
        cur_time += dis;
        cout<< secondNode.name<< " " << cur_time<<" " << cur_time<<endl;
        cur_time += dis;
        cout<< firstNode.name << " " <<cur_time << " " << cur_time <<endl;

        for(int i=0 ; i<nodes_num ; i++){
            for(int j=0;j<nodes_num ; j++){
                cout<<Matrix[i][j].distance << " ";
            }
            cout<<endl;
        }
        int s = 0;
        //cout<<travllingSalesmanProblem( s , nodes_num);

	}
}

void createMatrix(int num)
{
    Matrix = new Node*[num];
        for(int i=0;i<num;i++){
            Matrix[i]=new Node[num];
        }
    return;

}

