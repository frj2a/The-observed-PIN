#include<bits/stdc++.h>
using namespace std;


vector<string> solution (string pin) {

	map<char,string> neighbors = {
		{ '1', "124" },
		{ '2', "1235"},
		{ '3', "236"},
		{ '4', "1457"},
		{ '5', "14568"},
		{ '6', "3569"},
		{ '7', "478"},
		{ '8', "57890"},
		{ '9', "689"},
		{ '0', "80" }
	};

	int rate = 1;
	map<int,string> possibilities;

	for (int i = 0 ; i < (int)pin.size() ; i++) {
		possibilities[i] = neighbors[pin[i]];
		rate *= possibilities[i].size();
	}

	vector<string> result(rate);


	for (int i = 0; i < (int)possibilities.size(); i++) {
		rate /= possibilities[i].size();
		for (int j = 0 ; j < (int)result.size() ; j++) {
			result[j] += possibilities[i][(j/rate)%possibilities[i].size()];
		}

	}
	return result;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	string pin;
	cin >> pin;

	vector<string> out_;
	out_ = solution(pin);
		for(int i_out_ = 0; i_out_ < (int)out_.size(); i_out_++)
	{
		cout << out_[i_out_] << "\n";
	}
  return 0;
}
