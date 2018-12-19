package homework7;

public class BookSpecification {
	double price;
	String title;
	int type;
	String isbn;
	
	BookSpecification(double bprice, String btitle, int btype, String bisbn){
		price = bprice;
		title = btitle;
		type = btype;
		isbn = bisbn;
	}
	
	double getPrice() { return price;}
}
