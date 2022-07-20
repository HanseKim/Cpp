/**
 * @file 5525 IOIO.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 내 코드는 아니지만 좋은 코드라서 저장한다.
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
int main(void) {
   int n, m, state = 0, k = 0, result = 0;
   cin >> n >> m;
   char* a = new char[m+1];
   cin >> a;
   for (int i = 0; i < m; i++) {
      if (a[i] == 'I') {
         if (state == 2) {
            k++;
         }
         else if (state == 1) {
            if (n <= k) {
               result += k - n + 1;
            }
            k = 0;
         }
         state = 1;
      }
      else {
         if (state == 1) {
            state = 2;
         }
         else {
            state = 0;
            if (n <= k) {
               result += k - n + 1;
            }
            k = 0;
         }
      }
   }
   if (n <= k) {
      result += k - n + 1;
      k = 0;
   }
   cout << result;
   return 0;
}