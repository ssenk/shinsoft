foreach ('A'..'Z')
{
	# print $_;
	print;
}
print "\n";

for ('A'..'Z')
{
#	if( ord($_) % int(rand(7)+1) )
#	{
#		sideeffector();
#	}
	sideeffector() if( ord($_) % int(rand(7)+1) );
	# print $_;
	print;
}

sub sideeffector {
	# $_ =~ tr/A-Z/a-z/
	tr/A-Z/a-z/
}
