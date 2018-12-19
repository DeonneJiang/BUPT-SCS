package homework7;

import java.util.Set;

public class Controller {
	
	private BookCatalog bookcatalog = new BookCatalog();
	
	public Controller() {
		
	}
	
	
	public void addBook(BookSpecification newbook) {
		bookcatalog.books.add(newbook);
	}
	
	public BookCatalog getBookCatalog() {return bookcatalog;}
	
	
	
	public void addStrategy(IPricingStrategy news) {
		PricingStrategyFactory.getInstance().catalog.strategies.put(news.getNumber(), news);
	}
	
	
	public void deleteStrategy(String snumber) {
		PricingStrategyFactory.getInstance().catalog.strategies.remove(snumber);
	}
	
	
	
	public void updateStrategy(IPricingStrategy s) {
		IPricingStrategy ss = PricingStrategyFactory.getInstance().catalog.strategies.get(s.getNumber());

		PricingStrategyFactory.getInstance().catalog.strategies.remove(s.getNumber());
		PricingStrategyFactory.getInstance().catalog.strategies.put(s.getNumber(), s);
	}
	
	
	
	
	public void buyBook() {
		
		
		
	}
	
	
	
	public Sale getSale() {
		
		
		return null;
	}
	
	
//	public void testFunction1() {
//		for( BookSpecification b : bookcatalog.books) {
//			System.out.println(b.isbn);
//		}
//	}
//	
//	
//	public void testFunction2() {
//		Set<String> keyset = PricingStrategyFactory.getInstance().catalog.strategies.keySet();
//		for( String s : keyset){
//			System.out.println(PricingStrategyFactory.getInstance().catalog.strategies.get(s).toString());
//		}
//	}
	
	
}
