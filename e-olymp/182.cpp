#include <cstdio>
#include <algorithm>
#include <stdbool.h>
#define getAbilityG ability[i].second.first
#define getAbilityH ability[i].second.second
#define getAbility ability[i].second
#define getSelisih ability[i].first
using namespace std;

int main () {
    int troops, grunt, headhunter, res=0, gruntTrained=0, headhunterTrained=0;
    scanf("%d %d %d", &troops, &grunt, &headhunter);
    if(grunt+headhunter > troops) {
        printf("-1\n");
        return 0;
    } 
    pair<int, pair<int, int>> ability[troops];
    bool kind[troops]; // 1 = grunt ; 0 = headhunter
    for (int i=0; i<troops; i++) {
        scanf("%d %d", &getAbilityG, &getAbilityH);
        getSelisih = abs(getAbilityG - getAbilityH);
    }

    sort(ability, ability+troops);
    int selisihNol=0;
    for (int i=0; i<troops; i++) {
        if (getSelisih == 0){
            //default bila selisih == 0 maka tidak dijadikan grunt ataupun hunter
            selisihNol++;
            continue;
        }
        if (getAbilityG > getAbilityH) {
            kind[i] = true;
            res += getAbilityG;
            gruntTrained++;
        } else {
            kind[i] = false;
            res += getAbilityH;
            headhunterTrained++;
        }
    }

    int harusDiubahKeG = ((grunt > gruntTrained) ? grunt-gruntTrained : 0);
    int harusDiubahKeH = ((headhunter > headhunterTrained) ? headhunter-headhunterTrained : 0);
    for (int i = selisihNol; i < troops && selisihNol < harusDiubahKeG + harusDiubahKeH; i++) {
        if (harusDiubahKeG && getAbilityH - getAbilityG < 0) {
            res -= getAbilityH;
            res += getAbilityG;
            harusDiubahKeG--;
        } else if (harusDiubahKeH && getAbilityG - getAbilityH < 0) {
            res -= getAbilityG;
            res += getAbilityH;
            harusDiubahKeH--;
        }
    }
    for (int i=0; i < selisihNol; i++) {
        res += getAbilityG;
    }
    printf("%d\n", res);
    return 0;
}