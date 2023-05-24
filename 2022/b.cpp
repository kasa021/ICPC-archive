#include <bits/stdc++.h>
#include <cmath>

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)
#define all(vec) vec.begin(), vec.end()
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using graph = vector<vector<int>>;

int main()
{
    while(1){
        int n;
        cin>>n;
        if(n==0) break;
        vector<set<int>> st(n);
        deque<int> player; // playerの順番を管理する
        rep(i,n){
            int c1,c2;
            cin>>c1>>c2;
            if(c1!=c2){  // 初手配られた時点でカードが揃ってたら、捨てておく
                st[i].insert(c1);
                st[i].insert(c2);
                player.push_back(i);
            }
        }
        int ans=0;
        while(!player.empty()){
            ans++;
            int player_number=player.front();  // playerの番号を控えておく
            player.pop_front();

            int e=*begin(st[player_number]);  // playerが持っている最小のカードを捨てる
            st[player_number].erase(e);
            if(st[player_number].size()!=0) player.push_back(player_number); // まだカードを持っている場合順番に加える

            int next_player=player.front(),prev_size=st[next_player].size();
            st[next_player].insert(e); // 次のplayerにとったカードを入れる
            int now_size=st[next_player].size();
            if(prev_size==now_size){  // sizeが増えていなかったら、カードが揃った
                st[next_player].erase(e); // 揃ったカード捨てる
                if(st[next_player].size()==0) player.pop_front(); // カードがなくなったら、次の手順から消す
            }
        }
        cout<< ans << endl;
    }
}
