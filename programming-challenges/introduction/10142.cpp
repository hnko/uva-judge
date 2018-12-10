/* AC - introduction */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
struct Candidate{
	string name;
	int votes;
	bool eliminated;
};

Candidate candidates[21];
int ballots[1001][1001];

void reset_votes(){
	for(int i=1; i<21; i++) candidates[i].votes = 0;
}

void reset_eliminated(){
	for(int i=1; i<21; i++) candidates[i].eliminated = false;	
}

int greater_50(int num_voters, int num_candidates){
	for(int i=1; i<21; i++){
		if((double)candidates[i].votes > num_voters/2.0) return i;
	}
	return -1;
}

void count_votes(int num_voters, int num_candidates){
	for(int i=0; i < num_voters; i++){
		for(int j=0; j < num_candidates; j++){
			if(candidates[ballots[i][j]].eliminated == false){
				candidates[ballots[i][j]].votes++;
				break;
			}
		}
	}
}

bool eliminate(int num_candidates){
	int high = -1e6;
	int low = 1e6;
	for(int i=1; i<=num_candidates; i++){
		if(candidates[i].votes > high and candidates[i].eliminated == false){
			high = candidates[i].votes;
		}
		if(candidates[i].votes < low and candidates[i].eliminated == false){
			low = candidates[i].votes;
		}
	}
	if(high == low) return false;
	for(int i=1; i<=num_candidates; i++){
		if(candidates[i].votes == low){
			candidates[i].eliminated = true;
		}
	}
	return true;
}


int main(int argc, char const *argv[]){
	int t, aux, winner;
	string votes;
	cin >> t;
	cin.ignore();
	while(t--){
		int num_candidates, num_voters;
		
		cin >> num_candidates; cin.ignore();
		for(int i=1; i<=num_candidates; i++){
			getline(cin, candidates[i].name);
		}
		num_voters = 0;
		while(getline(cin, votes) and !votes.empty()){
			stringstream ss;
			ss << votes;
			int i=0;
			while(ss >> aux){
				ballots[num_voters][i++] = aux;
			}
			num_voters++;
		}

		reset_eliminated();

		do{
			reset_votes();
			
			count_votes(num_voters, num_candidates);
			
			winner = greater_50(num_voters, num_candidates);
			if(winner != -1) break;
		}while(eliminate(num_candidates));

		if(winner != -1){
			cout << candidates[winner].name << endl;
		}else{
			for(int i=1; i<=num_candidates; i++){
				if(candidates[i].eliminated == false){
					cout << candidates[i].name << endl;
				}
			}
		}
		if(t) cout << endl;

	}


	return 0;
}