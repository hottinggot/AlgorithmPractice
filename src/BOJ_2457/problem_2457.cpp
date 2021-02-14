//공주님의 정원

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct flower {
    int startM;
    int startD;
    int endM;
    int endD;
};

bool compare(const flower& f1, const flower& f2) {
    if(f1.startM==f2.startM) {
        return f1.startD<f2.startD;
    } else {
        return f1.startM<f2.startM;
    }
}

int main() {
    int n;
    cin >> n;

    vector<flower> list;
    int mm = 11;
    int dd = 30;
    int arr[mm+1][dd+1];

    for(int i=0; i<n; i++) {
        flower f;
        cin >> f.startM >> f.startD >> f.endM >> f.endD;

        list.push_back(f);
    }

    sort(list.begin(), list.end(), compare);

    int cnt = 0;

    int lastM = 3;
    int lastD = 1;
    while(1) {

        int maxEndM = 0;
        int maxEndD = 0;
        for(int i=0; i<list.size(); i++) {
            if(list[i].endM<lastM || (list[i].endM==lastM && list[i].endD<=lastD)) 
                continue;
            
            else if(list[i].startM<lastM || (list[i].startM==lastM &&list[i].startD<=lastD)) {
                if(maxEndM < list[i].endM || (maxEndM==list[i].endM && maxEndD<list[i].endD)) {
                    maxEndM = list[i].endM;
                    maxEndD = list[i].endD;
                }
            } else break;
        }
        lastM = maxEndM;
        lastD = maxEndD;

        if(maxEndM==0 && maxEndD==0) {
            cnt = 0;
            break;
        } else {
            cnt++;
        }
        if(lastM>11 || (lastM==11 && lastD>30)) {
            break;
        }
    }

    cout << cnt << '\n';

}