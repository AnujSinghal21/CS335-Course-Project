	.text
	beginfunc ShiftReduceParser.__init__@ShiftReduceParser@str
	#t_0 = popparam
	#t_1 = popparam
	#t_2 = 0
	#t_3 = #t_1 + #t_2
	*(#t_3) = #t_0
	endfunc 
	beginfunc LR0Parser.__init__@LR0Parser@str@str
	#t_5 = popparam
	#t_6 = popparam
	#t_7 = popparam
	#t_8 = 0
	#t_9 = #t_7 + #t_8
	*(#t_9) = #t_5
	endfunc 
	beginfunc CLRParser.__init__@CLRParser@str@str
	#t_11 = popparam
	#t_12 = popparam
	#t_13 = popparam
	#t_14 = 0
	#t_15 = #t_13 + #t_14
	*(#t_15) = #t_11
	endfunc 
	beginfunc LALRParser.__init__@LALRParser@str@str@str
	#t_17 = popparam
	#t_18 = popparam
	#t_19 = popparam
	#t_20 = popparam
	#t_21 = 0
	#t_22 = #t_19 + #t_21
	*(#t_22) = #t_18
	endfunc 
	beginfunc LALRParser.print_name@LALRParser
	#t_24 = popparam
	param "SLR name:"
	shiftpointer 8
	call print 1
	shiftpointer 0
	endfunc 
	beginfunc global.main
	param "Shift-Reduce"
	param "CLR"
	param "LALR"
	shiftpointer 24
	call LALRParser.__init__@LALRParser@str@str@str 3
	shiftpointer -24
	endfunc 
