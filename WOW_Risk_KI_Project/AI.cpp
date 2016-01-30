#include "AI.h"

AI::AI(Faction faction, GameBoard* board)
	:	Player(faction, true),
		gameBoard(board),
		randomChoiceValue(0.2f)
{
	std::vector<int> temp_Vec(4, 0);

	// Initialize actions #1 - #8 (phase 1 _ placeUnits)
	// [0] = actionNumber
	// [1] = placing terr
	// [2] = unitCount

	for(int i = 0; i < 9; i++)
	{
		temp_Vec.at(0) = i;
		temp_Vec.at(1) = i + 1;
		temp_Vec.at(2) = 1;
		allActions.push_back(temp_Vec);
	}

	// Initialize actions #9 - #31 (phase 2 _ conquerTerritory)
	// [0] = actionNumber
	// [1] = attacking? 0 == false / 1 == true
	// [2] = attacking from terrNumber
	// [3] = defender terrNumber
	// [4] = attacking unitCount (always attack with maximum Units (1-3 Units)) -> init later

	// action #9
	temp_Vec.at(0) = 9;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 1;
	temp_Vec.at(3) = 2;
	allActions.push_back(temp_Vec);

	// action #10
	temp_Vec.at(0) = 10;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 2;
	temp_Vec.at(3) = 1;
	allActions.push_back(temp_Vec);

	// action #11
	temp_Vec.at(0) = 11;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 2;
	temp_Vec.at(3) = 4;
	allActions.push_back(temp_Vec);

	// action #12
	temp_Vec.at(0) = 12;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 2;
	temp_Vec.at(3) = 7;
	allActions.push_back(temp_Vec);

	// action #13
	temp_Vec.at(0) = 13;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 3;
	temp_Vec.at(3) = 4;
	allActions.push_back(temp_Vec);

	// action #14
	temp_Vec.at(0) = 14;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 3;
	temp_Vec.at(3) = 5;
	allActions.push_back(temp_Vec);

	// action #15
	temp_Vec.at(0) = 15;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 3;
	temp_Vec.at(3) = 7;
	allActions.push_back(temp_Vec);

	// action #16
	temp_Vec.at(0) = 16;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 4;
	temp_Vec.at(3) = 2;
	allActions.push_back(temp_Vec);

	// action #17
	temp_Vec.at(0) = 17;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 4;
	temp_Vec.at(3) = 3;
	allActions.push_back(temp_Vec);;

	// action #18
	temp_Vec.at(0) = 18;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 4;
	temp_Vec.at(3) = 5;
	allActions.push_back(temp_Vec);

	// action #19
	temp_Vec.at(0) = 19;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 5;
	temp_Vec.at(3) = 3;
	allActions.push_back(temp_Vec);

	// action #20
	temp_Vec.at(0) = 20;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 5;
	temp_Vec.at(3) = 4;
	allActions.push_back(temp_Vec);

	// action #21
	temp_Vec.at(0) = 21;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 5;
	temp_Vec.at(3) = 6;
	allActions.push_back(temp_Vec);

	// action #22
	temp_Vec.at(0) = 22;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 6;
	temp_Vec.at(3) = 5;
	allActions.push_back(temp_Vec);

	// action #23
	temp_Vec.at(0) = 23;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 6;
	temp_Vec.at(3) = 7;
	allActions.push_back(temp_Vec);

	// action #24
	temp_Vec.at(0) = 24;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 7;
	temp_Vec.at(3) = 2;
	allActions.push_back(temp_Vec);

	// action #25
	temp_Vec.at(0) = 25;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 7;
	temp_Vec.at(3) = 3;
	allActions.push_back(temp_Vec);

	// action #26
	temp_Vec.at(0) = 26;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 7;
	temp_Vec.at(3) = 6;
	allActions.push_back(temp_Vec);

	// action #27
	temp_Vec.at(0) = 27;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 7;
	temp_Vec.at(3) = 8;
	allActions.push_back(temp_Vec);

	// action #28
	temp_Vec.at(0) = 28;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 7;
	temp_Vec.at(3) = 9;
	allActions.push_back(temp_Vec);

	// action #29
	temp_Vec.at(0) = 29;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 8;
	temp_Vec.at(3) = 7;
	allActions.push_back(temp_Vec);

	// action #30
	temp_Vec.at(0) = 30;
	temp_Vec.at(1) = 1;
	temp_Vec.at(2) = 9;
	temp_Vec.at(3) = 7;
	allActions.push_back(temp_Vec);

	// action #31
	temp_Vec.at(0) = 31;
	temp_Vec.at(1) = 0;
	allActions.push_back(temp_Vec);
}

AI::~AI()
{
	
}

// read old values from brain.txt
void AI::load()
{
	std::ifstream input_txt;
	input_txt.open("data/brain.txt");

	if(input_txt.fail())
	{
		std::cerr << "Failed to open brain.txt!" << std::endl;
	}

	std::vector<std::vector<float> > temp_q_values(32, std::vector<float>(262144, 0));

	int row = 0;

	for(std::string txt_line; std::getline(input_txt, txt_line); row++)
	{
		std::istringstream input_line(txt_line);

		float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F;
		input_line >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w >> x >> y >> z >> A >> B >> C >> D >> E >> F;
				
		temp_q_values[0][row] = a;
		temp_q_values[1][row] = b;
		temp_q_values[2][row] = c;
		temp_q_values[3][row] = d;
		temp_q_values[4][row] = e;
		temp_q_values[5][row] = f;
		temp_q_values[6][row] = g;
		temp_q_values[7][row] = h;
		temp_q_values[8][row] = i;
		temp_q_values[9][row] = j;
		temp_q_values[10][row] = k;
		temp_q_values[11][row] = l;
		temp_q_values[12][row] = m;
		temp_q_values[13][row] = n;
		temp_q_values[14][row] = o;
		temp_q_values[15][row] = p;
		temp_q_values[16][row] = q;
		temp_q_values[17][row] = r;
		temp_q_values[18][row] = s;
		temp_q_values[19][row] = t;
		temp_q_values[20][row] = u;
		temp_q_values[21][row] = v;
		temp_q_values[22][row] = w;
		temp_q_values[23][row] = x;
		temp_q_values[24][row] = y;
		temp_q_values[25][row] = z;
		temp_q_values[26][row] = A;
		temp_q_values[27][row] = B;
		temp_q_values[28][row] = C;
		temp_q_values[29][row] = D;
		temp_q_values[30][row] = E;
		temp_q_values[31][row] = F;
	}

	q_values = temp_q_values;	

	std::cout << "Test_q_value:" << q_values[2][2] << std::endl << std::endl;
	std::cout << "Test_q_value:" << q_values[3][3] << std::endl << std::endl;
}

// write new values in brain.txt
void AI::store()
{
	std::ofstream out("data/brain.txt");

	int q_value_storedCounter = 0;

	//				*-----------*  x = action
	//				|
	// 				|
	//				|
	//  y == state	*

	float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F;
	a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = q = r = s = t = u = v = w = x = y = z = A = B = C = D = E = F = 0;

	for(int y = 0; y < 262144; y++) // here: y = 2^18 states
	{
		if(y == vecTupel_VisitedStates.at(q_value_storedCounter).second)
		{
			switch(vecTupel_VisitedStates.at(q_value_storedCounter).first)
			{
			case 0:
				out << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 1:
				out << a << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 2:
				out << a << ' ' << b << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 3:
				out << a << ' ' << b << ' ' << c << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 4:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 5:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 6:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 7:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 8:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 9:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 10:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 11:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 12:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 13:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 14:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 15:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 16:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 17:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 18:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 19:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 20:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 21:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 22:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 23:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 24:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 25:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 26:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 27:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 28:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << D << ' ' << E << ' ' << F << '\n'; break;
			case 29:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << E << ' ' << F << '\n'; break;
			case 30:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << ' ' << F << '\n'; break;
			case 31:
				out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << vecNew_Q_Values.at(q_value_storedCounter) << '\n'; break;
			}
			q_value_storedCounter++;
		}
		else
		{
			// 32 '0' in each row
			out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << ' ' << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << o << ' ' << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << ' ' << u << ' ' << v << ' ' << w << ' ' << x << ' ' << y << ' ' << z << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << F << '\n';
		}
	}
	out.close();
}

// for creating a brain.txt with all states (262144 * 37 = 0) (only once for each AI!)
// CAUTION: OVERWRITES old brain.txt!
void AI::createEmptyTableOfValues()
{
	std::ofstream out("data/brain.txt");

	for(int y = 0; y < 262144; y++) // here: y = 2^18 states
	{
		// 32 '0' in each row
		out << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << '\n';
	}
	out.close();
}

// get current GameBoard and save it
void AI::setGameBoard(GameBoard* board)
{
	gameBoard = board;
}

// return the Q_Value for action - state
float AI::getQ_Value(const int& action, const int& state)
{
	return q_values[action][state];
}

// Calculate the reward/Q_Value for this game
float AI::calculateQ_Value(const std::string& currentState, const int& actionNumber, const int& phase, const float& old_Q_Value)
{
	float alpha = 0.7f; // Learn_Rate: Higher -> More impact from making actions
	float gamma = 0.8f; // Discount_Rate: Higher -> More weight of longterm-strategies
	float reward = 0.0f; // reward for a single action

	float currentQuality = old_Q_Value;
	float bestQuality = getQ_Value(getBestActionNumber(phase, currentState), binToDec(currentState));

	return ((1 - alpha) * currentQuality + alpha * (reward + gamma + bestQuality));
}

/*
Calculates the current state of game and returns it
Every Territory has 2 bits:

"00" == neutral Territory
"01" == Alliance has 1 Unit on Territory
"10" == Alliance has MORE than 1 Unit on Territory
"11" == Horde has 1 or more Unit on Territory
*/
const std::string AI::getCurrentState() const
{
	// Wird so interpretiert: "Terr 1 | Terr 2 | ... usw ... | Terr 9"
	std::string currentState = "000000000000000000";

	int temp_counter_terrs = 1;

	for(int i = 0; i < 18; i+=2, temp_counter_terrs++)
	{
		if(gameBoard->getSpecificTerritory(temp_counter_terrs).getTerrFaction().getFactionName().compare("Allianz") == 0)
		{
			if(gameBoard->getSpecificTerritory(temp_counter_terrs).getUnitCount() == 1)
			{
				currentState.at(i + 1) = '1';
			}
			else
			{
				currentState.at(i) = '1';
			}
		}

		if(gameBoard->getSpecificTerritory(temp_counter_terrs).getTerrFaction().getFactionName().compare("Horde") == 0)
		{
			currentState.at(i) = '1';
			currentState.at(i + 1) = '1';
		}
	}
	// String rückwärts zurückgeben, um später in Dezimalzahl umzuwandeln
	return std::string(currentState.rbegin(), currentState.rend());
}

// return action
std::vector<int> AI::chooseAction(const int& phaseNumber, std::string currentState)
{
	switch(phaseNumber)
	{
	case 1:
		{
			return agentPlaceUnits(currentState);
		}
	case 2:
		{
			return agentAttack(currentState);
		}
		
		/*
	case 3:
		{
			// return agentMoveUnits(currentState);
		}
		*/

	default:
		{
			std::cerr << "Wrong Phase_Number in AI::chooseAction!";
			return std::vector<int>();
		}
	}
}

// perform phase #1: place 1 Unit on friendly Territory
std::vector<int> AI::agentPlaceUnits(std::string currentState)
{
	// [0] = actionNumber
	// [1] = placing terr
	// [2] = unitCount

	int actionNumber;

	if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < randomChoiceValue)
	{
		// random action
		actionNumber = getAllPossibleActions(1, currentState).at(std::rand() % getAllPossibleActions(1, currentState).size());
	}
	else
	{
		// best action
		actionNumber = getBestActionNumber(1, currentState);
	}

	float new_Q_Value = calculateQ_Value(currentState, actionNumber, 1, getQ_Value(actionNumber, binToDec(currentState)));

	//Save visited state, action and new Q_Value
	vecTupel_VisitedStates.push_back(std::make_pair(binToDec(currentState), actionNumber));
	vecNew_Q_Values.push_back(new_Q_Value);

	return allActions.at(actionNumber);
}

// perform phase #2: attacking enemy territory
std::vector<int> AI::agentAttack(std::string currentState)
{
	// [0] = actionNumber
	// [1] = attacking? 0 == false / 1 == true
	// [2] = attacking from terrNumber
	// [3] = defender terrNumber
	// [4] = attacking unitCount (always attack with maximum Units (1-3 Units))

	int actionNumber;

	if((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) < randomChoiceValue)
	{
		// random action
		actionNumber = getAllPossibleActions(2, currentState).at(std::rand() % getAllPossibleActions(2, currentState).size());
	}
	else
	{
		// best action
		actionNumber = getBestActionNumber(2, currentState);
	}

	float new_Q_Value = calculateQ_Value(currentState, actionNumber, 2, getQ_Value(actionNumber, binToDec(currentState)));

	//Save visited state, action and new Q_Value
	vecTupel_VisitedStates.push_back(std::make_pair(binToDec(currentState), actionNumber));
	vecNew_Q_Values.push_back(new_Q_Value);

	return allActions.at(actionNumber);
}

/*
void AI::agentMoveUnits()
{
	std::string currentState = getCurrentState();


}
*/

// return all actions for this state
std::vector<int> AI::getAllPossibleActions(const int& phaseNumber, std::string state)
{
	std::string currentState = std::string(state.rbegin(), state.rend());
	std::vector<int> possibleActions;

	switch(phaseNumber)
	{
	case 1:
		{
			for(int i = 0; i < 9; i++)
			{
				std::string terrString;

				terrString.push_back(currentState.at(i * 2));
				terrString.push_back(currentState.at((i * 2) + 1));

				if(terrString.compare("11") == 0)
				{
					possibleActions.push_back(i);
				}
			}
			break;
		}
	case 2:
		{
			/*
			temp_enemyTerrVec:
			0 = neutral Territory
			1 = Alliance owns Territory
			2 = Horde owns Territory
			*/
			std::vector<int> temp_OwnershipTerrVec;

			for(int i = 0; i < 9; i++)
			{
				std::string temp_terrString;

				temp_terrString.push_back(currentState.at(i * 2));
				temp_terrString.push_back(currentState.at((i * 2) + 1));

				if(	temp_terrString.compare("01") == 0 ||
					temp_terrString.compare("10") == 0)
				{
					temp_OwnershipTerrVec.push_back(1);
				}
				if( temp_terrString.compare("11") == 0)
				{
					temp_OwnershipTerrVec.push_back(2);
				}
				if( temp_terrString.compare("00") == 0)
				{
					temp_OwnershipTerrVec.push_back(0);
				}
			}

			int possibleActionCounter = 9;

			for(int i = 0; i < 9; i++)
			{
				if(temp_OwnershipTerrVec.at(i) == 2) // compare if AI owns Territory
				{
					std::vector<int> temp_NeighborNumbersVec = gameBoard->getSpecificTerritory(i + 1).getVectorNeighborNumber();

					for(int j = 0; j < (int)temp_NeighborNumbersVec.size(); j++) // check all Neighbors
					{
						int temp_terNumber = temp_NeighborNumbersVec.at(j);

						if(temp_OwnershipTerrVec.at(temp_terNumber) == 1) // compare if Player owns Territory
						{
							possibleActions.push_back(possibleActionCounter); // add action to performable Actions
						}
						possibleActionCounter++;
					}
				}
				else
				{
					possibleActionCounter += gameBoard->getSpecificTerritory(i + 1).getVectorNeighborNumber().size();
				}
			}
			possibleActions.push_back(possibleActionCounter); // NoAttack_possibility (action #31)
			break;
		}
/*
	case 3:
		{
			addToPosiblility = ;
			break;
		}
*/
	default:
		{
			std::cerr << "Wrong PhaseNumber in AI::getAllPossibleActions()!" << std::endl;
			break;
		}
	}
	return possibleActions;
}

// return the best action for this state
int AI::getBestActionNumber(const int phaseNumber, const std::string& currentState)
{
	int state_dec = binToDec(currentState);

	float lowest_Q_Value = getQ_Value(0, state_dec);
	float highest_Q_Value = getQ_Value(0, state_dec);

	int bestActionNumber;

	for(int i = 0; i < 32; i++)
	{
		float temp_Q_Value = getQ_Value(i, state_dec);

		// get the highest Q_Value of currentState
		if(temp_Q_Value > highest_Q_Value)
		{
			highest_Q_Value = temp_Q_Value;
			bestActionNumber = i;
		}

		// get the lowest Q_Value of currentState
		if(temp_Q_Value < lowest_Q_Value)
		{
			lowest_Q_Value = temp_Q_Value;
		}
	}

	// if every Q_Value is equal, choose a random action
	if(highest_Q_Value == lowest_Q_Value)
	{
		bestActionNumber = getAllPossibleActions(phaseNumber, currentState).at(std::rand() % getAllPossibleActions(phaseNumber, currentState).size());
	}
	return bestActionNumber;
}

// change binary to decimal
int AI::binToDec(std::string state_bin)
{
	int result = 0;
	int pow = 1; // shiften

    for(int i = state_bin.length() - 1; i >= 0; i--, pow <<= 1)
	{
        result += (state_bin[i] - '0') * pow;
	}
    return result;
}