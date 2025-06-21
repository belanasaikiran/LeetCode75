class Solution {
public:
    string predictPartyVictory(string senate) {

        deque<int> R, D;

        for(int i = 0; i < senate.size(); i++){
            if(senate[i] == 'R') R.push_back(i);
            else D.push_back(i);
        }

        while(!R.empty() && !D.empty()){
            int Rc = R.front();
            int Dc = D.front();
            R.pop_front(); D.pop_front();
            if(Rc < Dc){
                R.push_back(Rc + senate.size());
            } else{
                D.push_back(Dc + senate.size());
            }
        }

        return !R.empty() ? "Radiant" : "Dire";
    }
};