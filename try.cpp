#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    unordered_set<string> readPermissions = {"read_settings", "read_intent"};
    unordered_set<string> additionalReadPermissions = {"read_dispute", "read_refund"};
    unordered_set<string> writePermissions = {"write_settings", "create_intent", "confirm_intent"};
    unordered_set<string> additionalWritePermissions = {"update_dispute", "create_dispute", "create_refund", "cancel_refund"};
    unordered_set<string> products = {"payments", "banking", "identity", "capital", "climate"};
    set<string> allPermissions = {
        "banking.confirm_intent",
        "banking.create_intent",
        "banking.read_intent",
        "banking.read_settings",
        "banking.write_settings",
        "capital.confirm_intent",
        "capital.create_intent",
        "capital.read_intent",
        "capital.read_settings",
        "capital.write_settings",
        "climate.confirm_intent",
        "climate.create_intent",
        "climate.read_intent",
        "climate.read_settings",
        "climate.write_settings",
        "identity.confirm_intent",
        "identity.create_intent",
        "identity.read_intent",
        "identity.read_settings",
        "identity.write_settings",
        "payments.cancel_refund",
        "payments.confirm_intent",
        "payments.create_dispute",
        "payments.create_intent",
        "payments.create_refund",
        "payments.read_dispute",
        "payments.read_intent",
        "payments.read_refund",
        "payments.read_settings",
        "payments.update_dispute",
        "payments.write_settings"};
    // 11000 1100 1111 0011 0100 1111 010111

    set<string> permissions;

    string keyMode;
    cin >> keyMode;
    int n;
    cin >> n;
    vector<string> roles(n);
    bool admin = false;
    for (auto &r : roles)
    {
        cin >> r;
        if (r == "admin")
            admin = true;
    }
    if (admin)
    {
        // for (auto p : products)
        // {
        //     for (auto rp : readPermissions)
        //     {
        //         permissions.insert(p + '.' + rp);
        //     }
        //     for (auto wp : writePermissions)
        //     {
        //         permissions.insert(p + '.' + wp);
        //     }
        //     if (p == "payments")
        //     {
        //         for (auto rp : additionalReadPermissions)
        //         {
        //             permissions.insert(p + '.' + rp);
        //         }
        //         for (auto wp : additionalWritePermissions)
        //         {
        //             permissions.insert(p + '.' + wp);
        //         }
        //     }
        // }
        permissions = allPermissions;
    }
    else
    {
        for (auto r : roles)
        {
            if (r == "admin_readonly")
            {
                for (auto p : products)
                {
                    for (auto rp : readPermissions)
                    {
                        permissions.insert(p + '.' + rp);
                    }
                    if (p == "payments")
                    {
                        for (auto rp : additionalReadPermissions)
                        {
                            permissions.insert(p + '.' + rp);
                        }
                    }
                }
            }
            if (products.find(r) != products.end())
            {
                for (auto rp : readPermissions)
                {
                    permissions.insert(r + '.' + rp);
                }
                for (auto wp : writePermissions)
                {
                    permissions.insert(r + '.' + wp);
                }
                if (r == "payments")
                {
                    for (auto rp : additionalReadPermissions)
                    {
                        permissions.insert(r + '.' + rp);
                    }
                    for (auto wp : additionalWritePermissions)
                    {
                        permissions.insert(r + '.' + wp);
                    }
                }
            }
        }
    }
    if (keyMode == "permissions")
    {

        for (auto p : permissions)
        {
            cout << p << endl;
        }
    }
    else if (keyMode == "full_token")
    {
        string token = "";
        for (auto ap : allPermissions)
        {
            if (permissions.find(ap) == permissions.end())
            {
                token += '0';
            }
            else
            {
                token += '1';
            }
        }
        cout << token << endl;
    }
    return 0;
}