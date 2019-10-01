#include<bits/stdc++.h>
using namespace std;

//Test Case
/*
Input:
A 20 2
B 15 2
C 10 1 
D 5 3
E 1 3

Output:
A, B, D
*/

struct Job{
public:    
    char id;
    int profit, deadline;

    Job(){
        this->id = '$';
        this->profit = 0;
        this->deadline = 0;
    }

    Job(char id, int profit, int deadline){
        this->id = id;
        this->profit = profit;
        this->deadline = deadline;
    }

};

bool JobComparator(Job a, Job b){ return a.profit > b.profit; }

vector<Job> inputJobs(int number){
    vector <Job> v(number);
    char id;
    int profit, deadline;
    for(int i=0; i<number; i++){
        cin >> id >> profit >> deadline ; 
        v[i] = Job(id, profit, deadline);
    }
    return v;
}

void displayJobs(int number, vector<Job> &v){
    cout << "id" << "\t" << "profit" << "\t" << "deadline" << "\n" ; 
    for(int i=0; i<number; i++){
        cout << v[i].id << "\t" << v[i].profit << "\t" << v[i].deadline << "\n" ; 
    }
    cout << endl;
}

int getMaxDeadline(vector<Job> &jobs){
    int maxDeadline = jobs[0].deadline;
    for(auto job = jobs.begin()+1; job != jobs.end(); job++){
        maxDeadline = max(maxDeadline, job->deadline);
    }
    return maxDeadline;
}

vector<Job> findOptimumJobSequence(vector<Job> &jobs){
    int maxDeadline = getMaxDeadline(jobs);
    vector<Job> sequencedJobs(maxDeadline);
    vector <int> profitsOfSequencedJobs(maxDeadline);

    sort(jobs.begin(), jobs.end(), JobComparator);

    int i=0, j=0;
    for(auto job=jobs.begin(); job!=jobs.end(); job++, i++){

        if(!profitsOfSequencedJobs[i]){ //Profit is not yet initialized
            sequencedJobs[job->deadline - 1] = *job;
            profitsOfSequencedJobs[job->deadline - 1] = job->profit;
        }
        else{
            for(int j=job->deadline -1; j>=0; j--){
                if(!profitsOfSequencedJobs[j]){ //Profit is not yet initialized
                    sequencedJobs[j] = *job;
                    profitsOfSequencedJobs[j] = job->profit;
                }                
            }
        }
    }

    return sequencedJobs;
}

void displaySequencedJobs(vector<Job> jobs){
    for(auto job=jobs.begin(); job!=jobs.end(); job++){
        cout << job->id << "\t" << job->profit << "\t" << job->deadline << "\n";
    }
    cout << endl;
}

int main(){
    int number=5;
    vector <Job> jobs = inputJobs(number);
    displayJobs(number, jobs);
    vector<Job> optimumSequence = findOptimumJobSequence(jobs);
    displaySequencedJobs(optimumSequence);
    return 0;
}