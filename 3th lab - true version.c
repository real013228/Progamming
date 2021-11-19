#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define YEAR 365 * DAY
#define MONTH 30 * 24 * 60 * 60
#define DAY 86400
#define HOUR 3600
#define MINUTE 60
#define BUFFSIZE 400
#define STRSIZE 1000
#define JUSTTWOMILLION 2000000
long long arr[JUSTTWOMILLION];
int main() {
    char *filename1 = "C:\\Users\\real0\\Downloads\\NASA_access_log_Jul95\\access_log_Jul95";
    char *filename2 = "arm";
    char str[STRSIZE];
    int ans1 = 0;
    FILE *f1;
    if ((f1 = fopen(filename1, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    //long long *arr = (long long *) malloc(JUSTTWOMILLION * sizeof(long long));
    // пока не дойдем до конца, считываем по 256 байт
    int cnt = 0;
    int status = 0;
    while ((fgets(str, STRSIZE, f1)) != NULL && cnt < 1891714) {
        // записываем строкu
        char
                remote_addr[BUFFSIZE] = {0},
                local_time[BUFFSIZE] = {0},
                request[BUFFSIZE] = {0},
                timeZone[BUFFSIZE] = {0},
                bytes_send[BUFFSIZE] = {0},
                status1[BUFFSIZE] = {0};
        int ind1 = 0;
        while (str[ind1] != '\"') {
            ind1 += 1;
        }
        int ind2 = ind1 + 1;
        int i = 0;
        while (str[ind2] != '\"') {
            request[i] = str[ind2];
            i += 1;
            ind2 += 1;
        }
        ind1 = 0;
        ind2 = 2;
//        printf("request : %s\n", request);
        sscanf(str, "%s - - %s %s", remote_addr, local_time, timeZone);
        while (str[strlen(str) - ind1 - 1] != ' ') {
            bytes_send[ind1] = str[strlen(str) - ind1 - 1];
            ind1 += 1;
        }
        while (str[strlen(str) - ind1 - ind2] != ' ') {
            status1[ind2 - 2] = str[strlen(str) - ind1 - ind2];
            ind2 += 1;
        }
        char tmpBytes[20];
        char tmpStatus[20];
        for (int ind = 0; ind < strlen(status1); ind++) {
            tmpStatus[ind] = status1[strlen(status1) - 1 - ind];
        }
        for (int ind = 0; ind < strlen(bytes_send); ind++) {
            tmpBytes[ind] = bytes_send[strlen(bytes_send) - 1 - ind];
        }
//        printf("bytes : %s\n", tmpBytes);
//        printf("status : %s\n", tmpStatus);
        if (tmpStatus[0] == '5') {
            ans1++;
        }
        long long
                hours = 0,
                minutes = 0,
                seconds = 0,
                days = 0,
                years = 0;
        char months[3];
        sscanf(local_time, "[%llu/%[a-zA-Z]/%llu:%llu:%llu:%llu", &days, months, &years, &hours, &minutes, &seconds);
//        printf("%llu/%s/%llu:%llu:%llu:%llu\n%s", days, months, years, hours, minutes, seconds, str);
//        printf("%llu\n", years);
        long long
                year = years * YEAR,
                day = days * DAY,
                hour = hours * HOUR,
                minute = minutes * MINUTE,
                month = 0,
                second = seconds;
        if (!strncmp(months, "Jan", 3)) {
            month = MONTH;
        }
        if (!strncmp(months, "Feb", 3)) {
            month = MONTH * 2;
        }
        if (!strncmp(months, "Mar", 3)) {
            month = MONTH * 3;
        }
        if (!strncmp(months, "Apr", 3)) {
            month = MONTH * 4;
        }
        if (!strncmp(months, "May", 3)) {
            month = MONTH * 5;
        }
        if (!strncmp(months, "Jun", 3)) {
            month = MONTH * 6;
        }
        if (!strncmp(months, "Jul", 3)) {
            month = MONTH * 7;
        }
        if (!strncmp(months, "Aug", 3)) {
            month = MONTH * 8;
        }
        if (!strncmp(months, "Sep", 3)) {
            month = MONTH * 9;
        }
        if (!strncmp(months, "Oct", 3)) {
            month = MONTH * 10;
        }
        if (!strncmp(months, "Nov", 3)) {
            month = MONTH * 11;
        }
        if (!strncmp(months, "Dec", 3)) {
            month = MONTH * 12;
        }
//        if(ans1 == 1891713 || ans1 == 1){
//            printf("%s\n", str);
//        }
//        fprintf(f2,"%llu %llu %llu %llu %llu %llu\n", day, month, year, hour, minute, second);
//        fprintf(f2, "%llu\n", second + minute + hour + day + month + year);
        if(cnt == 1891713){
            printf("%s",str);
        } else{
            arr[cnt] = second + minute + hour + day + month + year;
        }
        cnt++;
//        printf("%d\n", cnt);
    }
    long long timeInterval;
    long long maxi = 0;
    scanf("%lld", &timeInterval);
    for(long long i = 0; i < cnt - 1; i++){
        long long j = i + 1;
        long long ans = 0;
        while(arr[j] - arr[i] <= timeInterval && j < cnt){
            ans = j - i + 1;
            j++;
        }
        if(ans > maxi){
            maxi = ans;
        }
    }
    printf("%d %lld\n", ans1, maxi);
    fclose(f1);
    return 0;
}
//199.72.81.55 [01/Jul/1995:00:00:01  -0400] "GET /history/apollo/ 0 0
//199.72.81.55 [01/Jul/1995:00:00:01 -0400] "GET /history/apollo/ 0 0
