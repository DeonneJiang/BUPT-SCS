package homework7;

import java.util.ArrayList;

public class BookCatalog {
	ArrayList<BookSpecification> books;
	
	
	
	public BookCatalog() {
		BookSpecification tempbook;
		books = new ArrayList<BookSpecification>();
		tempbook = new BookSpecification(18,"UML与模式应用",2,"978-7-302-2");
		books.add(tempbook);
		tempbook = new BookSpecification(34,"Java与模式",1,"978-7-312-3");
		books.add(tempbook);
		tempbook = new BookSpecification(58,"HeadFirst 设计模式",1,"968-6-302-1");
		books.add(tempbook);
		tempbook = new BookSpecification(30,"爱丽丝历险记",3,"958-1-302-2");
		books.add(tempbook);
		tempbook = new BookSpecification(20,"煲汤大全",4,"900-7-392-2");
		books.add(tempbook);
	}
	
	
	
	public BookSpecification getBookSpecification(String bisbn) {
		
		for(BookSpecification b: books ) {
			if( b.isbn.equals(bisbn)) {
				return b;
			}
		}
		
		return null;
	}
}
