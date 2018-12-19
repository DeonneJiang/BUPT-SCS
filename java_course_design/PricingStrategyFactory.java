package homework7;

import java.util.Set;

public class PricingStrategyFactory {
	
	static private PricingStrategyFactory instance = new PricingStrategyFactory();
	
	StrategyCatalog catalog;
	
	public PricingStrategyFactory() {
		catalog = new StrategyCatalog();
	}
	
	
	static public PricingStrategyFactory getInstance() {
		return instance;
	}
	
	public IPricingStrategy getPricingStrategy(BookSpecification book){
		int type = book.type;
		Set<String> keyset = catalog.strategies.keySet();
		for( String s : keyset){
			if( catalog.strategies.get(s).getAdaptType() == type) {
				return catalog.strategies.get(s);
			}
		}
		NoDiscountStrategy ns  = new NoDiscountStrategy();
		return ns;
	}
	
	public void setCatalog(StrategyCatalog s) {
		catalog  = s;
	}
	
}
