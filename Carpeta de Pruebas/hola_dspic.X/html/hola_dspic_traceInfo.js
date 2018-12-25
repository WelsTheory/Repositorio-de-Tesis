function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/ADC */
	this.urlHashMap["hola_dspic:15"] = "hola_dspic.c:79,223&hola_dspic.h:70&MCHP_ADC1_Interrupt.c:4";
	/* <Root>/Bitwise
Operator */
	this.urlHashMap["hola_dspic:71"] = "hola_dspic.c:72";
	/* <Root>/Bitwise
Operator1 */
	this.urlHashMap["hola_dspic:72"] = "hola_dspic.c:84";
	/* <Root>/Bitwise
Operator2 */
	this.urlHashMap["hola_dspic:73"] = "hola_dspic.c:168";
	/* <Root>/Compiler Options */
	this.urlHashMap["hola_dspic:2"] = "msg=rtwMsg_notTraceable&block=hola_dspic:2";
	/* <Root>/Data Type Conversion */
	this.urlHashMap["hola_dspic:37"] = "hola_dspic.c:118,130&hola_dspic.h:72";
	/* <Root>/Data Type Conversion1 */
	this.urlHashMap["hola_dspic:49"] = "hola_dspic.c:164&hola_dspic.h:73";
	/* <Root>/Data Type Conversion2 */
	this.urlHashMap["hola_dspic:8"] = "hola_dspic.c:71";
	/* <Root>/Data Type Conversion3 */
	this.urlHashMap["hola_dspic:34"] = "hola_dspic.c:89";
	/* <Root>/Data Type Conversion4 */
	this.urlHashMap["hola_dspic:50"] = "hola_dspic.c:166";
	/* <Root>/Data Type Conversion5 */
	this.urlHashMap["hola_dspic:55"] = "msg=&block=hola_dspic:55";
	/* <Root>/Data Type Conversion6 */
	this.urlHashMap["hola_dspic:63"] = "msg=&block=hola_dspic:63";
	/* <Root>/FIR100 */
	this.urlHashMap["hola_dspic:61"] = "hola_dspic.c:88,113,255&hola_dspic.h:69,79&hola_dspic_data.c:24";
	/* <Root>/Microchip Master */
	this.urlHashMap["hola_dspic:1"] = "hola_dspic.c:219,221";
	/* <Root>/Product */
	this.urlHashMap["hola_dspic:58"] = "hola_dspic.c:83";
	/* <Root>/Product1 */
	this.urlHashMap["hola_dspic:64"] = "hola_dspic.c:167";
	/* <Root>/Shift Arithmetic */
	this.urlHashMap["hola_dspic:39"] = "hola_dspic.c:115";
	/* <Root>/Shift Arithmetic1 */
	this.urlHashMap["hola_dspic:52"] = "hola_dspic.c:165";
	/* <Root>/UART Configuration */
	this.urlHashMap["hola_dspic:13"] = "hola_dspic.c:234&MCHP_UART1_Interrupt.c:4";
	/* <Root>/UART Rx */
	this.urlHashMap["hola_dspic:14"] = "hola_dspic.c:33&hola_dspic.h:71";
	/* <Root>/UART Tx */
	this.urlHashMap["hola_dspic:45"] = "hola_dspic.c:132";
	/* <Root>/UART Tx1 */
	this.urlHashMap["hola_dspic:53"] = "hola_dspic.c:174";
	/* <S1>/Digital Output
Write */
	this.urlHashMap["hola_dspic:10:4"] = "hola_dspic.c:76";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "hola_dspic"};
	this.sidHashMap["hola_dspic"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "hola_dspic:10"};
	this.sidHashMap["hola_dspic:10"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/ADC"] = {sid: "hola_dspic:15"};
	this.sidHashMap["hola_dspic:15"] = {rtwname: "<Root>/ADC"};
	this.rtwnameHashMap["<Root>/Bitwise Operator"] = {sid: "hola_dspic:71"};
	this.sidHashMap["hola_dspic:71"] = {rtwname: "<Root>/Bitwise Operator"};
	this.rtwnameHashMap["<Root>/Bitwise Operator1"] = {sid: "hola_dspic:72"};
	this.sidHashMap["hola_dspic:72"] = {rtwname: "<Root>/Bitwise Operator1"};
	this.rtwnameHashMap["<Root>/Bitwise Operator2"] = {sid: "hola_dspic:73"};
	this.sidHashMap["hola_dspic:73"] = {rtwname: "<Root>/Bitwise Operator2"};
	this.rtwnameHashMap["<Root>/Compiler Options"] = {sid: "hola_dspic:2"};
	this.sidHashMap["hola_dspic:2"] = {rtwname: "<Root>/Compiler Options"};
	this.rtwnameHashMap["<Root>/Data Type Conversion"] = {sid: "hola_dspic:37"};
	this.sidHashMap["hola_dspic:37"] = {rtwname: "<Root>/Data Type Conversion"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "hola_dspic:49"};
	this.sidHashMap["hola_dspic:49"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "hola_dspic:8"};
	this.sidHashMap["hola_dspic:8"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "hola_dspic:34"};
	this.sidHashMap["hola_dspic:34"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "hola_dspic:50"};
	this.sidHashMap["hola_dspic:50"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/Data Type Conversion5"] = {sid: "hola_dspic:55"};
	this.sidHashMap["hola_dspic:55"] = {rtwname: "<Root>/Data Type Conversion5"};
	this.rtwnameHashMap["<Root>/Data Type Conversion6"] = {sid: "hola_dspic:63"};
	this.sidHashMap["hola_dspic:63"] = {rtwname: "<Root>/Data Type Conversion6"};
	this.rtwnameHashMap["<Root>/Digital Output1"] = {sid: "hola_dspic:10"};
	this.sidHashMap["hola_dspic:10"] = {rtwname: "<Root>/Digital Output1"};
	this.rtwnameHashMap["<Root>/FIR100"] = {sid: "hola_dspic:61"};
	this.sidHashMap["hola_dspic:61"] = {rtwname: "<Root>/FIR100"};
	this.rtwnameHashMap["<Root>/Microchip Master"] = {sid: "hola_dspic:1"};
	this.sidHashMap["hola_dspic:1"] = {rtwname: "<Root>/Microchip Master"};
	this.rtwnameHashMap["<Root>/Product"] = {sid: "hola_dspic:58"};
	this.sidHashMap["hola_dspic:58"] = {rtwname: "<Root>/Product"};
	this.rtwnameHashMap["<Root>/Product1"] = {sid: "hola_dspic:64"};
	this.sidHashMap["hola_dspic:64"] = {rtwname: "<Root>/Product1"};
	this.rtwnameHashMap["<Root>/Shift Arithmetic"] = {sid: "hola_dspic:39"};
	this.sidHashMap["hola_dspic:39"] = {rtwname: "<Root>/Shift Arithmetic"};
	this.rtwnameHashMap["<Root>/Shift Arithmetic1"] = {sid: "hola_dspic:52"};
	this.sidHashMap["hola_dspic:52"] = {rtwname: "<Root>/Shift Arithmetic1"};
	this.rtwnameHashMap["<Root>/UART Configuration"] = {sid: "hola_dspic:13"};
	this.sidHashMap["hola_dspic:13"] = {rtwname: "<Root>/UART Configuration"};
	this.rtwnameHashMap["<Root>/UART Rx"] = {sid: "hola_dspic:14"};
	this.sidHashMap["hola_dspic:14"] = {rtwname: "<Root>/UART Rx"};
	this.rtwnameHashMap["<Root>/UART Tx"] = {sid: "hola_dspic:45"};
	this.sidHashMap["hola_dspic:45"] = {rtwname: "<Root>/UART Tx"};
	this.rtwnameHashMap["<Root>/UART Tx1"] = {sid: "hola_dspic:53"};
	this.sidHashMap["hola_dspic:53"] = {rtwname: "<Root>/UART Tx1"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "hola_dspic:10:71"};
	this.sidHashMap["hola_dspic:10:71"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/Digital Output Write"] = {sid: "hola_dspic:10:4"};
	this.sidHashMap["hola_dspic:10:4"] = {rtwname: "<S1>/Digital Output Write"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
