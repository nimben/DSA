/* Problem Statement: While playing an RPG game, you were assigned to complete one of the hardest quests in this game. There are n monsters you’ll need to defeat in this quest.

Each monster i is described with two integer numbers – poweri and bonusi. To defeat this monster, you’ll need at least poweri experience points. If you try fighting this monster without having enough experience points, you lose immediately. You will also gain bonusi experience points if you defeat this monster. You can defeat monsters in any order.
The quest turned out to be very hard – you try to defeat the monsters but keep losing repeatedly. Your friend told you that this quest is impossible to complete.
Knowing that, you’re interested, what is the maximum possible number of monsters you can defeat?

(Question difficulty level: Hardest)

Input:

The first line contains an integer, n, denoting the number of monsters. The next line contains an integer, e, denoting your initial experience.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, poweri, which represents power of the corresponding monster.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, bonusi, which represents bonus for defeating the corresponding monster.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e, defeated =0;
    cout<<"Enter the number of monsters: ";
    cin>>n;
    cout<<"Enter your initial experience: ";
    cin>>e;
    vector<long long> pow(n), bonus(n);

    cout<<"Enter the power of each monster: ";
    for(int i=0;i<n;i++){
        cin>>pow[i];
    }

    cout<<"Enter the bonus for defeating each monster: ";
    for(int i=0;i<n;i++){
        cin>>bonus[i];
    }

    vector<pair<long long, long long>> monster;
    for(int i=0;i<n;i++){
        monster.push_back({pow[i], bonus[i]});
    }

    sort(monster.begin(), monster.end());

    priority_queue<long long>pq;
    int i = 0;

    while(true){
        while(i<n && monster[i].first <= e){
            pq.push(monster[i].second);
            i++;
        }

        if(pq.empty())
            break;

        long long bonus = pq.top();
        pq.pop();

        e += bonus;
        defeated++;
    }
    cout << "Total monsters defeated : " << defeated;
}