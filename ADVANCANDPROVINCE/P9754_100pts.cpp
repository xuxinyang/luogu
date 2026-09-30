#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Member {
    string name;
    int type;
    ll offset;
};
struct Type {
    ll size, align;
    vector<Member> members;
};
ll roundUp(ll x, ll a)
{
    return (x + a - 1) / a * a;
}
int main()
{
    int n;
    cin >> n;
    vector<Type> types = {{1, 1, {}}, {2, 2, {}}, {4, 4, {}}, {8, 8, {}}};
    map<string, int> id = {
        {"byte", 0}, {"short", 1}, {"int", 2}, {"long", 3}
    };
    vector<Member> vars;
    ll tail = 0;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string name;
            int k;
            cin >> name >> k;
            Type t{0, 1, {}}; 
            while (k--)
            {
                string typename_, member;
                cin >> typename_ >> member;
                int j = id[typename_];
                t.align = max(t. align, types[j].align);
                t.size = roundUp(t.size, types[j].align);
                t.members.push_back({member, j, t.size});
                t.size += types[j].size;
            }
            t.size = roundUp(t.size, t.align);
            id[name] = types.size();
            types.push_back(t);
            cout << t.size << " " << t.align << "\n";
        }
        else if (op == 2)
        {
            string tn, name;
            cin >> tn >> name;
            int j = id[tn];
            tail = roundUp(tail, types[j].align);
            vars.push_back({name, j, tail});
            cout << tail << "\n";
            tail += types[j].size;
        }
        else if (op == 3)
        {
            string path;
            cin >> path;
            replace(path.begin(), path.end(), '.', ' ');
            istringstream in(path);
            string part;
            const vector<Member>* members = &vars;
            ll address = 0;
            while (in >> part)
            {
                for (auto & v : *members)
                {
                    if (v.name == part)
                    {

                        address += v.offset;
                        members = &types[v.type].members;
                        break;
                    }
                }
            }
            cout << address << "\n";
        }
        else
        {
            ll address;
            cin >> address;
            const vector<Member> *members = &vars;
            string path;
            bool ok = false;
            while (true)
            {
                const Member* found = nullptr;
                for (auto & v : *members)
                {
                    if (v.offset <= address && address < v.offset + types[v.type].size)
                    {
                        found = &v;
                        break;
                    }
                }
                if (!found) break;
                address -= found->offset;
                if (!path.empty()) path += '.';
                path += found->name;
                if (found->type < 4)
                {
                    ok = true;
                    break;
                }
                members = &types[found->type].members;
            }
            cout << (ok ? path : "ERR") << "\n";
        }
    }
    return 0;
}