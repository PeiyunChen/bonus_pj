
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
                else if(Matrix[k][k].name == second_name){
                    sec_idx = Matrix[k][k].idx;
                }
            }
            //cout << first_idx << " " << sec_idx<< endl;
            file>>Matrix[first_idx][sec_idx].distance;
            Matrix[sec_idx][first_idx].distance = Matrix[first_idx][sec_idx].distance;



        }



        for(int i=0 ; i<nodes_num ; i++){
            for(int j=0;j<nodes_num ; j++){
                cout<<Matrix[i][j].distance << " ";
            }
            cout<<endl;
        }
        int s = 0;
        cout<<travllingSalesmanProblem( s , nodes_num);

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

int travllingSalesmanProblem( int s , int V)
{
    // store all vertex apart from source vertex
    int weight=0;
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    while (next_permutation(vertex.begin(), vertex.end())){
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += Matrix[k][vertex[i]].distance;


            if(Matrix[k][k].visited == false) {

                weight+= Matrix[k][k].weight;
                Matrix[k][k].visited = true;
            }
            if(Matrix[vertex[i]][vertex[i]].visited == false) {

                Matrix[vertex[i]][vertex[i]].visited = true;
                weight+= Matrix[vertex[i]][vertex[i]].weight;
            }
            //weight+= Matrix[k][k].weight;
            //cout<<k << " " << vertex.size() <<endl;

            k = vertex[i];

        }
        current_pathweight += Matrix[k][s].distance;
        //cout<<Matrix[s][s].name<<endl;
        // update minimum
        min_path = min(min_path, current_pathweight);


    }

/*

    do {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += Matrix[k][vertex[i]].distance;


            if(Matrix[k][k].visited == false) {

                weight+= Matrix[k][k].weight;
                Matrix[k][k].visited = true;
            }
            if(Matrix[vertex[i]][vertex[i]].visited == false) {

                Matrix[vertex[i]][vertex[i]].visited = true;
                weight+= Matrix[vertex[i]][vertex[i]].weight;
            }
            //weight+= Matrix[k][k].weight;
            //cout<<k << " " << vertex.size() <<endl;

            k = vertex[i];

        }
        current_pathweight += Matrix[k][s].distance;
        //cout<<Matrix[s][s].name<<endl;
        // update minimum
        min_path = min(min_path, current_pathweight);
        //min_path  = current_pathweight;
    } while (next_permutation(vertex.begin(), vertex.end()));
*/
    cout<<weight<<endl;
    return min_path;
}
/*#include<stdio.h>

int ary[10][10],completed[10],n,cost=0;
int least(int c);
void takeInput()
{
	int i,j;

	printf("Enter the number of villages: ");
	scanf("%d",&n);

	printf("\nEnter the Cost Matrix\n");

	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row: %d\n",i+1);

		for( j=0;j < n;j++)
			scanf("%d",&ary[i][j]);

		completed[i]=0;
	}

	printf("\n\nThe cost list is:");

	for( i=0;i < n;i++)
	{
		printf("\n");

		for(j=0;j < n;j++)
			printf("\t%d",ary[i][j]);
	}
}

void mincost(int city)
{
	int i,ncity;

	completed[city]=1;

	printf("%d--->",city+1);
	ncity=least(city);
OBOBOB
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=ary[city][ncity];

		return;
	}

	mincost(ncity);
}

OBOBOBint least(int c)
{
	int i,nc=999;
	int min=999,kmin;

OBOBOB	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=999)
		cost+=kmin;

OBOBOB	return nc;
}

int main()
{
	takeInput();

	printf("\n\nThe Path is:\n");
OBOBOB	mincost(0); //passing 0 because starting vertex

	printf("\n\nMinimum cost is %d\n ",cost);
OBOBOB
	return 0;
}
*//*
// do_while_statement.cpp
#include <stdio.h>
int main()
{
    int i = 0;
    while (i < 3)
    {
        printf("\n%d",i++);
OBOBOB    }
}*/
