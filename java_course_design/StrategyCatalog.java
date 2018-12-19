package homework7;

import java.util.ArrayList;
import java.util.HashMap;

public class StrategyCatalog {
	HashMap<String, IPricingStrategy> strategies;
	
	public StrategyCatalog() {
		
//initialize the hash map
		strategies = new HashMap<String, IPricingStrategy>();
		
		FlatRateStrategy fs = new FlatRateStrategy("Discount001", "����ֵ�Żݲ���1",1,2);
		strategies.put(fs.getNumber(),fs);
		
		PercentageStrategy ps = new PercentageStrategy("Discount002", "�ٷֱ��ۿ۲���1" , 3,7);
		strategies.put(ps.getNumber(),ps);
		
		ps = new PercentageStrategy("Discount003", "�ٷֱ��ۿ۲���2" , 1,3);
		strategies.put(ps.getNumber(),ps);
		
		ArrayList<IPricingStrategy> sstrategies = new ArrayList<IPricingStrategy>();
		sstrategies.add(fs);
		sstrategies.add(ps);
		CompositeStrategy cs = new CompositeStrategy(sstrategies,"Discount004", "�˿����Ų���1", 4);
		strategies.put(cs.getNumber(),cs);
		
	}
	
}
