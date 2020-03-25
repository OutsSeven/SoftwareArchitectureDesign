#include "p_DataBaseOp.h"

using namespace DBHelper;

void DBHelper::p_DataBaseOp::connect()
{
	disconnect();//disconnect before connection

	if (_pstMql == NULL) {//initalize database pointer
		_pstMql = mysql_init(NULL);
	}

	if (!_dbc._charset.empty()) {//automatically set charset
		if (mysql_options(_pstMql, MYSQL_SET_CHARSET_NAME, _dbc._charset.c_str())) {
			throw DBHelper_Exception(string("p_DataBaseOp::connect: mysql_options MYSQL_SET_CHARSET_NAME") +
				_dbc._charset + ":" + string(mysql_error(_pstMql)));
		}
	}

	//do connection
	if (mysql_real_connect(_pstMql,_dbc._host.c_str(),_dbc._user.c_str(),_dbc._password.c_str(),
		_dbc._database.c_str(),_dbc._port,NULL,_dbc._flag) == NULL) {
		throw DBHelper_Exception("[DbHelper::connect]: mysql_real_connect: " + string(mysql_error(_pstMql)));
	}

	bConnected = true;
}

void DBHelper::p_DataBaseOp::disconnect()
{
	if (_pstMql != NULL) {
		mysql_close(_pstMql);
		_pstMql = mysql_init(NULL);
	}

	bConnected = false;
}

void DBHelper::p_DataBaseOp::execute(const string& sSql)
{
	if (!bConnected) {//if it's not connectted
		connect();
	}

	_sLastSql = sSql;

	size_t iRet = mysql_real_query(_pstMql, sSql.c_str(), sSql.length());
	if (iRet != 0) {//error
		int iErrno = mysql_errno(_pstMql);
		if (iErrno == 2013 || iErrno == 2006) {
			//reconnect
			connect();
			iRet= mysql_real_query(_pstMql, sSql.c_str(), sSql.length());
		}
	}

	if (iRet != 0) {
		throw DBHelper_Exception("[p_DataBaseOp::execute]: mysql_query:[" + sSql + "]:" + string(mysql_error(_pstMql)));
	}
}

OrderInfo DBHelper::p_DataBaseOp::selectOrder(const string& ip, bool isId)
{
	string sSelectSQL;
	if (isId) { sSelectSQL = "select * from OrderRecord where " + OrderRecord[1] + "=" + ip; }
	else { sSelectSQL = "select * from OrderRecord where " + OrderRecord[3] + " = " + ip; }
	if (!isOrderExist(ip, isId)) { return NULL; }
	vector<string> iInfo = getSelectInfo(sSelectSQL);

	OrderInfo order(iInfo[0], iInfo[1], iInfo[2], iInfo[3], stoi(iInfo[4]), iInfo[5]);
	return order;
}

MaskInfo DBHelper::p_DataBaseOp::selectMaskInfo(const string& place, const string& type)
{
	string sSelectSQL = "select * from MaskInformation where " + MaskInformation[0] + "='" +
		place + "' and " + MaskInformation[1] + "='" + type + "'";
	cout << sSelectSQL << endl;
	if (!isMaskExist(place, type)) { return NULL; }
	vector<string> iInfo = getSelectInfo(sSelectSQL);

	MaskInfo mi(iInfo[0], iInfo[1], stoi(iInfo[2]));
	return mi;
}

vector<string> DBHelper::p_DataBaseOp::getSelectInfo(const string& sSql)
{
	execute(sSql);

	MYSQL_RES* result = mysql_store_result(_pstMql);//get result

	vector<string> iInfo;

	//deal with result getted
	if (NULL == result) {
		printf("error(%d):%s\n", mysql_errno(_pstMql), mysql_error(_pstMql));
	}
	else {
		unsigned int num_field = mysql_num_fields(result);//get number of fields
		MYSQL_ROW row;
		//for each row
		while (row = mysql_fetch_row(result))//row should be only one result
		{
			unsigned long* length = mysql_fetch_lengths(result);
			//get field
			for (size_t i = 0; i < num_field; ++i) {
				iInfo.push_back(row[i]);
			}
		}
		mysql_free_result(result);
	}
	return iInfo;
}
