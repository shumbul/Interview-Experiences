#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Pizza {
    string name;
    int price_S;
    int price_M;
    int price_L;
};
struct OrderItem {
    string name;
    string size; // "Small", "Medium", "Large"
    int quantity;
};
// Get the price of a pizza by name and size
int getPrice(const vector<Pizza>& menu, const string& name, const string& size) {
    for (const auto& p : menu) {
        if (p.name == name) {
            if (size == "Small") 
              return p.price_S;
            if (size == "Medium") 
              return p.price_M;
            if (size == "Large") 
              return p.price_L;
        }
    }
    return INT_MAX; // Shouldn't happen
}
int noDiscount(const vector<Pizza>& menu, const vector<OrderItem>& order) {
    int total = 0;
    for (const auto& item : order) {
        total += item.quantity * getPrice(menu, item.name, item.size);
    }
    return total;
}
// Discount 1: Buy 3, cheapest is free
int discount1(const vector<Pizza>& menu, const vector<OrderItem>& order) {
    vector<int> allPrices;
    for (const auto& item : order) {
        int price = getPrice(menu, item.name, item.size);
        for (int i = 0; i < item.quantity; ++i) {
            allPrices.push_back(price);
        }
    }
    int total = 0;
    sort(allPrices.begin(), allPrices.end()); // Cheapest at front
    int n = allPrices.size();
    int freeCnt = n / 3; // Every 3 pizzas: 1 is free
    for (int i = 0; i < n; ++i) {
        if (i < freeCnt) 
            continue; // The cheapest freeCnt are free
        total += allPrices[i];
    }
    return total;
}
// Discount 2: Buy 5 for 100
int discount2(const vector<Pizza>& menu, const vector<OrderItem>& order) {
    vector<int> allPrices;
    for (const auto& item : order) {
        int price = getPrice(menu, item.name, item.size);
        for (int i = 0; i < item.quantity; ++i) {
            allPrices.push_back(price);
        }
    }
    int total = 0;
    sort(allPrices.begin(), allPrices.end(), greater<int>()); // Most expensive to cheapest
    int n = allPrices.size();
    int bundleCnt = n / 5;
    int left = n % 5;
    total += bundleCnt * 100;
    for (int i = 0; i < left; ++i)
        total += allPrices[i + bundleCnt * 5];
    return total;
}
// Discount 3: For every Large pizza, get a free Small one (cheapest small pizza)
int discount3(const vector<Pizza>& menu, const vector<OrderItem>& order) {
    int total = 0;
    int largeCnt = 0;
    vector<int> smallPrices;
    for (const auto& item : order) {
        int price = getPrice(menu, item.name, item.size);
        if (item.size == "Large") 
          largeCnt += item.quantity;
        if (item.size == "Small") {
            for (int i = 0; i < item.quantity; ++i)
                smallPrices.push_back(price);
        }
        total += item.quantity * price;
    }
    sort(smallPrices.begin(), smallPrices.end()); // Cheapest first
    int freeCnt = min(largeCnt, static_cast<int>(smallPrices.size()));
    for (int i = 0; i < freeCnt; ++i) {
        total -= smallPrices[i]; // Deduct cheapest small pizza for each large
    }
    return total;
}
// Discount 4: Buy 3 Large, pay for 3 Medium
int discount4(const vector<Pizza>& menu, const vector<OrderItem>& order) {
    // Only applies to Large pizzas
    int total = 0;
    struct LargePizza { int mediumPrice, largePrice; };
    vector<LargePizza> larges;
    for (const auto& item : order) {
        if (item.size == "Large") {
            int mediumPrice = getPrice(menu, item.name, "Medium");
            int largePrice = getPrice(menu, item.name, "Large");
            for (int i = 0; i < item.quantity; ++i)
                larges.push_back({mediumPrice, largePrice});
        }
    }
    sort(larges.begin(), larges.end(), [](const LargePizza& a, const LargePizza& b){
        return a.largePrice > b.largePrice; // Most expensive first
    });
    int n = larges.size();
    int groupCnt = n / 3;
    int left = n % 3;
    for (int g = 0; g < groupCnt; ++g) {
        // For each group of 3 larges, pay for their mediums
        total += larges[g * 3 + 0].mediumPrice;
        total += larges[g * 3 + 1].mediumPrice;
        total += larges[g * 3 + 2].mediumPrice;
    }
    // The remaining gets paid as large
    for (int i = 0; i < left; ++i)
        total += larges[groupCnt * 3 + i].largePrice;
    // Don't forget other pizzas
    for (const auto& item : order) {
        if (item.size != "Large") {
            int price = getPrice(menu, item.name, item.size);
            total += item.quantity * price;
        }
    }
    return total;
}
int solution(vector<Pizza>& menu, vector<OrderItem>& order) {
    int minTotal = INT_MAX;
    minTotal = min(minTotal, noDiscount(menu, order));
    minTotal = min(minTotal, discount1(menu, order));
    minTotal = min(minTotal, discount2(menu, order));
    minTotal = min(minTotal, discount3(menu, order));
    minTotal = min(minTotal, discount4(menu, order));
    return minTotal;
}
