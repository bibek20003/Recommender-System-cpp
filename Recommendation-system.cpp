#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

class RecommenderSystem {
private:
    map<string, map<string, double>> ratings;

public:
    void addRating(string user, string item, double rating) {
        ratings[user][item] = rating;
    }

    vector<pair<string, double>> recommendBasedOnItem(string itemName, int topN = 8) {
        map<string, double> score;
        map<string, double> similaritySum;

        map<string, double> itemRatings;

        for (auto &u : ratings) {
            if (u.second.count(itemName))
                itemRatings[u.first] = u.second.at(itemName);
        }

        for (auto &otherUser : ratings) {
            if (!itemRatings.count(otherUser.first)) continue;

            double sim = itemRatings[otherUser.first];

            for (auto &itm : otherUser.second) {
                if (itm.first != itemName) {
                    score[itm.first] += sim * itm.second;
                    similaritySum[itm.first] += sim;
                }
            }
        }

        vector<pair<string, double>> recommendations;

        for (auto &it : score) {
            double predicted = it.second / similaritySum[it.first];
            recommendations.push_back({it.first, predicted});
        }

        sort(recommendations.begin(), recommendations.end(),
             [](auto &a, auto &b){ return a.second > b.second; });

        if (recommendations.size() > topN)
            recommendations.resize(topN);

        return recommendations;
    }
};

int main() {
    RecommenderSystem rs;

    // =======================
    // EXPANDED RATING DATASET
    // =======================
    vector<string> items = {
        "Laptop", "Mouse", "Keyboard", "Monitor", "Headphones",
        "Smartphone", "Tablet", "Smartwatch", "Printer", "WiFi Router",
        "Webcam", "Gaming Chair", "Desk Lamp", "External HDD",
        "SSD", "Graphics Card", "Microphone", "Earbuds", "Power Bank",
        "Bluetooth Speaker", "Projector", "Camera", "TV", "VR Headset",
        "USB Hub", "Flash Drive"
    };

    // UserA
    rs.addRating("UserA", "Laptop", 5);
    rs.addRating("UserA", "Mouse", 4);
    rs.addRating("UserA", "Headphones", 5);
    rs.addRating("UserA", "Monitor", 3);
    rs.addRating("UserA", "Desk Lamp", 4);

    // UserB
    rs.addRating("UserB", "Keyboard", 5);
    rs.addRating("UserB", "Laptop", 4);
    rs.addRating("UserB", "Graphics Card", 5);
    rs.addRating("UserB", "Gaming Chair", 4);
    rs.addRating("UserB", "SSD", 4);

    // UserC
    rs.addRating("UserC", "Smartphone", 5);
    rs.addRating("UserC", "Tablet", 4);
    rs.addRating("UserC", "Smartwatch", 5);
    rs.addRating("UserC", "Power Bank", 4);
    rs.addRating("UserC", "Earbuds", 5);

    // UserD
    rs.addRating("UserD", "Monitor", 5);
    rs.addRating("UserD", "Keyboard", 4);
    rs.addRating("UserD", "Printer", 4);
    rs.addRating("UserD", "Webcam", 3);
    rs.addRating("UserD", "WiFi Router", 5);

    // UserE
    rs.addRating("UserE", "Camera", 5);
    rs.addRating("UserE", "Tripod", 4);
    rs.addRating("UserE", "Laptop", 3);
    rs.addRating("UserE", "Flash Drive", 5);
    rs.addRating("UserE", "External HDD", 4);

    // UserF
    rs.addRating("UserF", "TV", 5);
    rs.addRating("UserF", "Bluetooth Speaker", 4);
    rs.addRating("UserF", "Projector", 5);
    rs.addRating("UserF", "VR Headset", 4);

    // UserG
    rs.addRating("UserG", "Microphone", 5);
    rs.addRating("UserG", "Webcam", 4);
    rs.addRating("UserG", "Headphones", 4);
    rs.addRating("UserG", "USB Hub", 5);

    // =======================
    // ITEM SELECTION MENU
    // =======================

    cout << "********** SHOPPING MENU **********\n";
    for (int i = 0; i < items.size(); i++) {
        cout << i+1 << ". " << items[i] << "\n";
    }

    cout << "\nChoose an item (1-" << items.size() << "): ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > (int)items.size()) {
        cout << "Invalid choice.\n";
        return 0;
    }

    string selectedItem = items[choice - 1];
    cout << "\nYou selected: " << selectedItem << "\n";

    // =======================
    // SHOW RECOMMENDATIONS
    // =======================

    auto recs = rs.recommendBasedOnItem(selectedItem, 8);

    cout << "\nRecommended items based on your choice:\n";
    for (auto &r : recs) {
        cout << "- " << r.first << " (score: " << r.second << ")\n";
    }

    return 0;
}
