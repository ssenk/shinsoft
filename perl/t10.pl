
my $hashvar = {

	scalar => {
		description => "single item",
		signal => '$',
		},

	array => {
		description => "ordered list of items",
		signal => '@',
		},

	hash => {
		description => "key/value pairs",
		signal => '%',
		},

	};

print "Scalars begin with a $hashvar->{'scalar'}->{'signal'}\n";

my @list = ("one", "two", "three", "four", "five");
my %hash = (
	"one"   => "1st", 
	"two"   => "2nd", 
	"three" => "3rd", 
	"four"  => "4th", 
	"five"  => "5th",
	"1st"   => "one"  , 
	"2nd"   => "two"  , 
	"3rd"   => "three", 
	"4th"   => "four" , 
	"5th"   => "five" 
	);

print $list[$_],"\n" foreach 0..1;
print $#list," $_\n" foreach (@list);
print $#list," $list[$_]\n" foreach 0 .. $#list;

foreach my $key (sort keys %hash)
{
	print "The value of $key is $hash{$key}\n" ;
}
