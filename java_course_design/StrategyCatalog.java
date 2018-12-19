package homework7;

import java.util.ArrayList;
import java.util.HashMap;

public class StrategyCatalog {
	HashMap<String, IPricingStrategy> strategies;
	
	public StrategyCatalog() {
		
//initialize the hash map
		strategies = new HashMap<String, IPricingStrategy>();
		
		FlatRateStrategy fs = new FlatRateStrategy("Discount001", "绝对值优惠策略1",1,2);
		strategies.put(fs.getNumber(),fs);
		
		PercentageStrategy ps = new PercentageStrategy("Discount002", "百分比折扣策略1" , 3,7);
		strategies.put(ps.getNumber(),ps);
		
		ps = new PercentageStrategy("Discount003", "百分比折扣策略2" , 1,3);
		strategies.put(ps.getNumber(),ps);
		
		ArrayList<IPricingStrategy> sstrategies = new ArrayList<IPricingStrategy>();
		sstrategies.add(fs);
		sstrategies.add(ps);
		CompositeStrategy cs = new CompositeStrategy(sstrategies,"Discount004", "顾客最优策略1", 4);
		strategies.put(cs.getNumber(),cs);
		
	}
	
}
