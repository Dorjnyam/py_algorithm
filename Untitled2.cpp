#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <string>
#include <utility>
using namespace std;
#define int long long
string s, ss;
vector<pair<int, string>> v;
int error2, error1, too;
map<string, int> mymap;
int utga(int k)
{
	int l;
	if (k == 1)
	{
		l = rand() % 9 + 1;
	}
	if (k == 2)
	{
		l = rand() % 90 + 10;
	}
	if (k == 3)
	{
		l = rand() % 900 + 100;
	}
	if (k == 4)
	{
		l = rand() % 9000 + 1000;
	}
	if (k == 5)
	{
		l = rand() % 90000 + 10000;
	}
	if (k == 6)
	{
		l = rand() % 900000 + 100000;
	}
	if (k == 7)
	{
		l = rand() % 9000000 + 1000000;
	}
	if (k == 8)
	{
		l = rand() % 90000000 + 10000000;
	}
	return l;
}
int urj(int x, int y)
{
	string d;
	char xx[10], yy[10];
	itoa(x, xx, 10);
	itoa(y, yy, 10);
	d = xx;
	d += 'x';
	d = d + yy;
	v.push_back({x * y, d});
	return x * y;
}
int huv(int x, int y)
{
	string d;
	char xx[10], yy[10];
	itoa(x, xx, 10);
	itoa(y, yy, 10);
	d = xx;
	d += ':';
	d = d + yy;
	if (y == 0)
	{
		error1 = 1;
		return 1;
	}
	if (x % y != 0)
	{
		error1 = 1;
	}
	else
	{
		v.push_back({x / y, d});
		return x / y;
	}
}
int nem(int x, int y)
{
	string d;
	char xx[10], yy[10];
	itoa(x, xx, 10);
	itoa(y, yy, 10);
	d = xx;
	d += '+';
	d = d + yy;
	v.push_back({x + y, d});
	return x + y;
}
int has(int x, int y)
{
	string d;
	char xx[10], yy[10];
	itoa(x, xx, 10);
	itoa(y, yy, 10);
	d = xx;
	d = d + '-';
	d = d + yy;
	v.push_back({x - y, d});
	if (x - y < 0)
	{
		error2 = 1;
	}
	return x - y;
}
string compres(string s1)
{
	s1 = s1 + ' ';
	string p;
	int t = -1;
	for (int i = 0; s1[i]; i++)
	{
		t++;
		if (s1[i] < 48 || s1[i] > 57)
		{
			p += t + 48;
			t = -1;
			if (s1[i] != ' ')
				p = p + s1[i];
		}
	}
	return p;
}
void hevleh(int x)
{
	for (int i = 1; i < ss.size() - 1; i++)
		cout << ss[i];
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << ' ' << v[i].first << " ";
		string s1 = compres(v[i].second);
		if (mymap.count(s1) > 0)
			cout << mymap[s1];
		cout << endl;
	}
	cout << endl;
}
void ID()
{
	mymap["1+1"] = 40;
	mymap["2+1"] = 42;
	mymap["1-1"] = 46;
	mymap["1x1"] = 47;
	mymap["2+2"] = 69;
	mymap["2-1"] = 78;
	mymap["2-2"] = 84;
	mymap["2:1"] = 91;
	mymap["2x1"] = 97;
	mymap["2x4"] = 100;
	mymap["3+2"] = 103;
	mymap["3+3"] = 105;
	mymap["3-2"] = 109;
	mymap["3-3"] = 112;
	mymap["3x2"] = 120;
	mymap["3x3"] = 122;
	mymap["4+4"] = 125;
	mymap["4-4"] = 128;
	mymap["4:1"] = 131;
	mymap["4:2"] = 134;
	mymap["4:3"] = 135;
	mymap["4x1"] = 138;
	mymap["4x2"] = 141;
	mymap["4x3"] = 146;
	mymap["4x4"] = 147;
	mymap["5:2"] = 158;
	mymap["5:3"] = 160;
	mymap["5x3"] = 161;
	mymap["6:1"] = 165;
	mymap["6:2"] = 167;
	mymap["6:3"] = 168;
	mymap["6x2"] = 171;
	mymap["7:1"] = 175;
	mymap["7:2"] = 176;
	mymap["7:4"] = 178;
	mymap["7x1"] = 179;
	mymap["1+1"] = 180;
	mymap["1-1"] = 181;
	mymap["1:1"] = 182;
	mymap["1x1"] = 183;
	mymap["1+2"] = 184;
	mymap["1-2"] = 185;
	mymap["1:2"] = 186;
	mymap["1x2"] = 187;
	mymap["1+3"] = 188;
	mymap["1-3"] = 189;
	mymap["1:3"] = 190;
	mymap["1x3"] = 191;
	mymap["1+4"] = 192;
	mymap["1-4"] = 193;
	mymap["1:4"] = 194;
	mymap["1x4"] = 195;
	mymap["1+5"] = 196;
	mymap["1-5"] = 197;
	mymap["1:5"] = 198;
	mymap["1x5"] = 199;
	mymap["1+6"] = 200;
	mymap["1-6"] = 201;
	mymap["1:6"] = 202;
	mymap["1x6"] = 203;
	mymap["1+7"] = 204;
	mymap["1-7"] = 205;
	mymap["1:7"] = 206;
	mymap["1x7"] = 207;
	mymap["2+1"] = 208;
	mymap["2-1"] = 209;
	mymap["2:1"] = 210;
	mymap["2x1"] = 211;
	mymap["2+2"] = 212;
	mymap["2-2"] = 213;
	mymap["2:2"] = 214;
	mymap["2x2"] = 215;
	mymap["2+3"] = 216;
	mymap["2-3"] = 217;
	mymap["2:3"] = 218;
	mymap["2x3"] = 219;
	mymap["2+4"] = 220;
	mymap["2-4"] = 221;
	mymap["2:4"] = 222;
	mymap["2x4"] = 223;
	mymap["2+5"] = 224;
	mymap["2-5"] = 225;
	mymap["2:5"] = 226;
	mymap["2x5"] = 227;
	mymap["2+6"] = 228;
	mymap["2-6"] = 229;
	mymap["2:6"] = 230;
	mymap["2x6"] = 231;
	mymap["2+7"] = 232;
	mymap["2-7"] = 233;
	mymap["2:7"] = 234;
	mymap["2x7"] = 235;
	mymap["3+1"] = 236;
	mymap["3-1"] = 237;
	mymap["3:1"] = 238;
	mymap["3x1"] = 239;
	mymap["3+2"] = 240;
	mymap["3-2"] = 241;
	mymap["3:2"] = 242;
	mymap["3x2"] = 243;
	mymap["3+3"] = 244;
	mymap["3-3"] = 245;
	mymap["3:3"] = 246;
	mymap["3x3"] = 247;
	mymap["3+4"] = 248;
	mymap["3-4"] = 249;
	mymap["3:4"] = 250;
	mymap["3x4"] = 251;
	mymap["3+5"] = 252;
	mymap["3-5"] = 253;
	mymap["3:5"] = 254;
	mymap["3x5"] = 255;
	mymap["3+6"] = 256;
	mymap["3-6"] = 257;
	mymap["3:6"] = 258;
	mymap["3x6"] = 259;
	mymap["3+7"] = 260;
	mymap["3-7"] = 261;
	mymap["3:7"] = 262;
	mymap["3x7"] = 263;
	mymap["4+1"] = 264;
	mymap["4-1"] = 265;
	mymap["4:1"] = 266;
	mymap["4x1"] = 267;
	mymap["4+2"] = 268;
	mymap["4-2"] = 269;
	mymap["4:2"] = 270;
	mymap["4x2"] = 271;
	mymap["4+3"] = 272;
	mymap["4-3"] = 273;
	mymap["4:3"] = 274;
	mymap["4x3"] = 275;
	mymap["4+4"] = 276;
	mymap["4-4"] = 277;
	mymap["4:4"] = 278;
	mymap["4x4"] = 279;
	mymap["4+5"] = 280;
	mymap["4-5"] = 281;
	mymap["4:5"] = 282;
	mymap["4x5"] = 283;
	mymap["4+6"] = 284;
	mymap["4-6"] = 285;
	mymap["4:6"] = 286;
	mymap["4x6"] = 287;
	mymap["4+7"] = 288;
	mymap["4-7"] = 289;
	mymap["4:7"] = 290;
	mymap["4x7"] = 291;
	mymap["5+1"] = 292;
	mymap["5-1"] = 293;
	mymap["5:1"] = 294;
	mymap["5x1"] = 295;
	mymap["5+2"] = 296;
	mymap["5-2"] = 297;
	mymap["5:2"] = 298;
	mymap["5x2"] = 299;
	mymap["5+3"] = 300;
	mymap["5-3"] = 301;
	mymap["5:3"] = 302;
	mymap["5x3"] = 303;
	mymap["5+4"] = 304;
	mymap["5-4"] = 305;
	mymap["5:4"] = 306;
	mymap["5x4"] = 307;
	mymap["5+5"] = 308;
	mymap["5-5"] = 309;
	mymap["5:5"] = 310;
	mymap["5x5"] = 311;
	mymap["5+6"] = 312;
	mymap["5-6"] = 313;
	mymap["5:6"] = 314;
	mymap["5x6"] = 315;
	mymap["5+7"] = 316;
	mymap["5-7"] = 317;
	mymap["5:7"] = 318;
	mymap["5x7"] = 319;
	mymap["6+1"] = 320;
	mymap["6-1"] = 321;
	mymap["6:1"] = 322;
	mymap["6x1"] = 323;
	mymap["6+2"] = 324;
	mymap["6-2"] = 325;
	mymap["6:2"] = 326;
	mymap["6x2"] = 327;
	mymap["6+3"] = 328;
	mymap["6-3"] = 329;
	mymap["6:3"] = 330;
	mymap["6x3"] = 331;
	mymap["6+4"] = 332;
	mymap["6-4"] = 333;
	mymap["6:4"] = 334;
	mymap["6x4"] = 335;
	mymap["6+5"] = 336;
	mymap["6-5"] = 337;
	mymap["6:5"] = 338;
	mymap["6x5"] = 339;
	mymap["6+6"] = 340;
	mymap["6-6"] = 341;
	mymap["6:6"] = 342;
	mymap["6x6"] = 343;
	mymap["6+7"] = 344;
	mymap["6-7"] = 345;
	mymap["6:7"] = 346;
	mymap["6x7"] = 347;
	mymap["7+1"] = 348;
	mymap["7-1"] = 349;
	mymap["7:1"] = 350;
	mymap["7x1"] = 351;
	mymap["7+2"] = 352;
	mymap["7-2"] = 353;
	mymap["7:2"] = 354;
	mymap["7x2"] = 355;
	mymap["7+3"] = 356;
	mymap["7-3"] = 357;
	mymap["7:3"] = 358;
	mymap["7x3"] = 359;
	mymap["7+4"] = 360;
	mymap["7-4"] = 361;
	mymap["7:4"] = 362;
	mymap["7x4"] = 363;
	mymap["7+5"] = 364;
	mymap["7-5"] = 365;
	mymap["7:5"] = 366;
	mymap["7x5"] = 367;
	mymap["7+6"] = 368;
	mymap["7-6"] = 369;
	mymap["7:6"] = 370;
	mymap["7x6"] = 371;
	mymap["7+7"] = 372;
	mymap["7-7"] = 373;
	mymap["7:7"] = 374;
	mymap["7x7"] = 375;
}
main()
{
	ID();
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (cin >> s)
	{
		too = 10;
		s = '(' + s + ')';
		while (too--)
		{
			ss.clear();
			v.clear();
			error2 = 0;
			error1 = 0;
			stack<int> st1;
			stack<char> st2;
			for (int i = 0; s[i]; i++)
			{
				if (s[i] == '(' || s[i] == '+' || s[i] == '-')
				{
					st2.push(s[i]);
					ss += s[i];
				}
				if (s[i] >= 48 && s[i] <= 57)
				{
					st1.push(utga(s[i] - 48));
					char buffer[20];
					itoa(st1.top(), buffer, 10);
					ss += buffer;
				}
				if (s[i] == 'x')
				{
					if (s[i + 1] != '(')
					{
						int k = st1.top();
						st1.pop();
						int m = utga(s[i + 1] - 48);
						st1.push(urj(k, m));
						char buffer[20];
						ss += 'x';
						itoa(m, buffer, 10);
						ss += buffer;
						i++;
						continue;
					}
					else
					{
						st2.push('x');
						ss += 'x';
						continue;
					}
				}
				if (s[i] == ':')
				{
					if (s[i + 1] != '(')
					{
						int k = st1.top();
						st1.pop();
						int m = utga(s[i + 1] - 48);
						st1.push(huv(k, m));
						char buffer[20];
						ss += ':';
						itoa(m, buffer, 10);
						ss += buffer;
						i++;
						continue;
					}
					else
					{
						st2.push(':');
						ss += ':';
						continue;
					}
				}
				if (s[i] == ')')
				{
					ss += ')';
					stack<int> v1;
					stack<char> v2;
					while (st2.top() != '(')
					{
						v2.push(st2.top());
						st2.pop();
						v1.push(st1.top());
						st1.pop();
					}
					int b = 0;
					b = st1.top();
					st1.pop();
					st2.pop();
					while (!v2.empty())
					{
						if (v2.top() == '+')
						{
							b = nem(b, v1.top());
						}
						if (v2.top() == '-')
						{
							b = has(b, v1.top());
						}
						v1.pop();
						v2.pop();
					}
					if (st2.size() > 0 && st2.top() == 'x')
					{
						int m = st1.top();
						st1.pop();
						st1.push(urj(m, b));
						st2.pop();
					}
					else if (st2.size() > 0 && st2.top() == ':')
					{
						int m = st1.top();
						st1.pop();
						st1.push(huv(m, b));
						st2.pop();
					}
					else
						st1.push(b);
				}
			}
			if (error1 + error2 == 0)
			{
				hevleh(st1.top());
				st1.pop();
			}
			else
			{
				too++;
			}
		}
	}
}
