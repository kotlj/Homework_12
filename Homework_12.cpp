
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int spearman_hp = 0;
    int spearman_dmg = 0;
    int dragon_hp = 0;
    int dragon_dmg = 0;
    cout << "Enter spearman HP/DMG :\n";
    cin >> spearman_hp >> spearman_dmg;
    cout << "Enter dragon HP/DMG :\n";
    cin >> dragon_hp >> dragon_dmg;
    int dragon_hp_copy = dragon_hp;
    int spearman_hp_copy = spearman_hp;
    int n_of_sp = 0;
    for (n_of_sp; dragon_hp > 0; n_of_sp++)
    {
        spearman_hp = spearman_hp_copy * n_of_sp;
        dragon_hp = dragon_hp_copy;
        while (dragon_hp > 0 && spearman_hp > 0)
        {
            dragon_hp -= spearman_dmg * (spearman_hp / spearman_hp_copy) + (spearman_hp % spearman_hp_copy > 0 ? 1 : 0);
            if (dragon_hp > 0 && spearman_hp > 0)
            {
                spearman_hp -= dragon_dmg;
            }
        }
    }
    dragon_hp = dragon_hp_copy;
    spearman_hp = n_of_sp * spearman_hp_copy;
    while (dragon_hp > 0)
    {
        dragon_hp -= spearman_dmg * (spearman_hp / spearman_hp_copy) + (spearman_hp % spearman_hp_copy > 0 ? 1 : 0);
        cout << "@ Human turn\tDamage - " << spearman_dmg * (spearman_hp / spearman_hp_copy) + (spearman_hp % spearman_hp_copy > 0 ? 1 : 0)\
            << " Dragon HP - " << dragon_hp;
        cout << "\n";
        if (dragon_hp > 0 && spearman_hp > 0)
        {
            spearman_hp -= dragon_dmg;
            cout << "@ Dragon turn\tDamage - " << dragon_dmg << " spearmans alive - " << spearman_hp / spearman_hp_copy;
            if (spearman_hp % spearman_hp_copy > 0)
                cout << "spearman Dammaged - 1 (" << spearman_hp % spearman_hp_copy << ")";
            cout << "\n";
        }
    }
    cout << "\nMin of spearmans - " << n_of_sp;
}