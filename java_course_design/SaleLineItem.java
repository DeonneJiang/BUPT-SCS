package homework7;

public class SaleLineItem {
	int copies;
	BookSpecification bookSpec;
	IPricingStrategy strategy;
	
	SaleLineItem(int quantity, BookSpecification book){
		copies = quantity;
		bookSpec = book;
		strategy = PricingStrategyFactory.getInstance().getPricingStrategy(bookSpec);
	}

	double getSubTotal() {
		return strategy.getSubTotal(this);
	}
}
