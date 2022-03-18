#define CURL_STATICLIB
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <windows.h>
#include <nlohmann/json.hpp>
#include "Currency.h"
#include "Currencies.h"

static size_t getResponseToString(void* contents, size_t size, size_t nMemB, void* userP){
    ((std::string*) userP)->append((char*)contents, size*nMemB);
    return size * nMemB;
}

void initialize(std::vector<std::string>& mapPa){
    mapPa[0] = "AUD";
    mapPa[1] = "AZN";
    mapPa[2] = "GBP";
    mapPa[3] = "AMD";
    mapPa[4] = "BYN";
    mapPa[5] = "BGN";
    mapPa[6] = "BRL";
    mapPa[7] = "HUF";
    mapPa[8] = "HKD";
    mapPa[9] = "DKK";
    mapPa[10] = "USD";
    mapPa[11] = "EUR";
    mapPa[12] = "INR";
    mapPa[13] = "KZT";
    mapPa[14] = "CAD";
    mapPa[15] = "KGS";
    mapPa[16] = "CNY";
    mapPa[17] = "MDL";
    mapPa[18] = "NOK";
    mapPa[19] = "PLN";
    mapPa[20] = "RON";
    mapPa[21] = "XDR";
    mapPa[22] = "SGD";
    mapPa[23] = "TJS";
    mapPa[24] = "TRY";
    mapPa[25] = "TMT";
    mapPa[26] = "UZS";
    mapPa[27] = "UAH";
    mapPa[28] = "CZK";
    mapPa[29] = "SEK";
    mapPa[30] = "CHF";
    mapPa[31] = "ZAR";
    mapPa[32] = "KRW";
    mapPa[33] = "JPY";
}

enum nameOfValue{AUD, AZN, GBP, AMD, BYN, BGN, BRL, HUF, HKD, DKK, USD, EUR, INR, KZT, CAD, KGS, CNY, MDL, NOK, PLN, RON, XDR, SGD, TJS, TRY, TMT, UZS, UAH, CZK, SEK, CHF, ZAR, KRW, JPY };

int main() {
    int reQuires;
    std::cout << "How many requires do u want to do?:\n";
    std::cin >> reQuires;
    Currencies ans(reQuires);
    std::vector<std::string> mapPa(COUNTOFVALUES);
    initialize(mapPa);
    for(int cnt = 0; cnt < reQuires; ++cnt) {
        std::string str_result;
        CURL *curl = curl_easy_init();
        CURLcode result;
        if (!curl) {
            std::cout << "init failed\n";
            return EXIT_FAILURE;
        }
        std::ios_base::sync_with_stdio(false);
        size_t d = 0;
        //set options

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponseToString);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_result);

        //per form out action
        result = curl_easy_perform(curl);
        if (result != CURLE_OK) {
            std::cout << "download problem: \n" << curl_easy_strerror(result);
        }
        nlohmann::json j = nlohmann::json::parse(str_result);
        Currency currency;

        for(int i = 0; i < COUNTOFVALUES; i++) {
            ans.values[cnt][i].id = j["Valute"][mapPa[i]]["ID"].get<std::string>();
            ans.values[cnt][i].numCode = j["Valute"][mapPa[i]]["NumCode"].get<std::string>();
            ans.values[cnt][i].charCode = j["Valute"][mapPa[i]]["CharCode"].get<std::string>();
            ans.values[cnt][i].nominal = j["Valute"][mapPa[i]]["Nominal"].get<int>();
            ans.values[cnt][i].name = j["Valute"][mapPa[i]]["Name"].get<std::string>();
            ans.values[cnt][i].value = j["Valute"][mapPa[i]]["Value"].get<float>();
            ans.values[cnt][i].previous = j["Valute"][mapPa[i]]["Previous"].get<float>();
        }
        std::cout << str_result;
        curl_easy_cleanup(curl);
        Sleep(TIME);
    }
    std::cout << '\n' << ans.medium(JPY, reQuires) << ' ' << ans.middle(USD, reQuires) << '\n';
    return EXIT_SUCCESS;
}
