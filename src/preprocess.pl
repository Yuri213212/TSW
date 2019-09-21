BEGIN{
	binmode STDIN,":utf8";
	print("//");
}

s/(.)/ord($1)<128?$1:sprintf("U%x",ord($1))/ge;
