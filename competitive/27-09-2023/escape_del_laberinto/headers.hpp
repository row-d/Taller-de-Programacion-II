#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <bits/stdc++.h>
using namespace std;

#define READ_UNTIL_NOT_EOF(PATTERN, ...) while (scanf(PATTERN, __VA_ARGS__) != EOF)
#define FOR(i, init, len) for (unsigned int i = init; i < len; i++)
#define FOR_RANGE(start, len) FOR(i, 0, len)
#define CASES         \
  unsigned int cases; \
  cin >> cases;       \
  FOR(c, 0, cases)
#define CEROS_LEFT(n) __buildtin_ctz(n)
#define READ(type, var) \
  type var;             \
  cin >> var
#define READ_ARRAY(type, var, len) \
  type var[len];                   \
  FOR_RANGE(i, len)                \
  cin >> var[i]

#define READ_CONTAINER(type, var, len) \
  type var(len);                       \
  FOR_RANGE(i, len)                    \
  cin >> var.at(i)

#define REDIRECT_STD(input, output) \
  freopen(input, "r", stdin);       \
  freopen(output, "w", stdout);
#endif