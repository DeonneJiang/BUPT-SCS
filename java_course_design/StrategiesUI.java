package homework7;


import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.util.Set;

public class StrategiesUI extends JDialog{

	private Controller controller;
	
	public StrategiesUI(Controller pcontroller) {
		setSize(800,600);
		controller = pcontroller;
		
		
// create the panel
		JPanel  panel = new JPanel();
		
// create the buttons
		JButton addButton = new JButton("添加策略");
		JButton deleteButton = new JButton("删除策略");
		JButton updateButton = new JButton("更新策略");
		
// create the table which shows all the books
		DefaultTableModel model = new DefaultTableModel();
        model.addColumn("策略编号");
        model.addColumn("策略名称");
        model.addColumn("策略类型");
        model.addColumn("适用图书类型");
        model.addColumn("优惠额度");
		
        JTable table = new JTable(model);
        
        // add strategies to the table
        
        Set<String> keyset = PricingStrategyFactory.getInstance().catalog.strategies.keySet();
        for( String key : keyset) {
        	
        	IPricingStrategy s = PricingStrategyFactory.getInstance().catalog.strategies.get(key);
        	String s1 = s.getNumber();
        	String s2 = s.getName();
        	String s3 = s.getClass().getSimpleName();
        	String s4 = Integer.toString(s.getAdaptType());
        	String s5;
        	switch(s.getClass().getSimpleName()) {
        	case "PercentageStrategy":
        		s5 = Integer.toString(((PercentageStrategy)s).discountPercentage);
        		break;
        	case "FlatRateStrategy":
        		s5 = Double.toString(((FlatRateStrategy)s).discountPerBook);
        		break;
        	case "CompositeStrategy":
        		s5 = "";
        		for(IPricingStrategy ss:  ((CompositeStrategy)s).strategies) {
        			s5 += ss.getNumber();
        			s5 += " ";
        		}
        		
        		break;
        	default:
        		s5 = "";
        		break;
        	}
        	
        	Object a[] = {
                    s1,s2,s3,s4,s5
                };
        	model.addRow(a);
        	
        }

// attach operations to the button         
        //TODO
        addButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				
				// create all the objects to be used
				JLabel numberLabel = new JLabel("策略编号:");
                JLabel nameLabel = new JLabel("策略名称:");
                JLabel typeLabel = new JLabel("策略类型:");
                JLabel adapttypeLabel = new JLabel("适用图书类型:");
                JLabel discountLabel = new JLabel("优惠额度:");

                JTextField numberField = new JTextField(15);
                JTextField nameField = new JTextField(15);
                JTextField typeField = new JTextField(15);
                JTextField adapttypeField = new JTextField(15);
                JTextField discountField = new JTextField(15);

                JButton okButton = new JButton("ok");
                JPanel p1 = new JPanel();
                JDialog f1 = new JDialog();
                
                
                
                okButton.addActionListener(new ActionListener() {

					@Override
					public void actionPerformed(ActionEvent arg0) {
						// TODO Auto-generated method stub
						String s1,s2,s3,s4,s5;
						s1 = numberField.getText();
						s2 = nameField.getText();
						s3 = typeField.getText();
						s4 = adapttypeField.getText();
						s5 = discountField.getText();
						
						switch(s3) {
						case "PercentageStrategy":
							PercentageStrategy ps = new PercentageStrategy(s1, s2 , Integer.parseInt(s4),Integer.parseInt(s5));
			        		controller.addStrategy(ps);
			        		Object a[] = {
			                        s1,s2,s3,s4,s5
			                    };
			            	model.addRow(a);
							break;
			        	case "FlatRateStrategy":
			        		FlatRateStrategy fs = new FlatRateStrategy(s1,s2,Double.valueOf(s5).doubleValue(),Integer.parseInt(s4));
			        		controller.addStrategy(fs);
			        		Object b[] = {
			                        s1,s2,s3,s4,s5
			                    };
			            	model.addRow(b);
			        		break;
			        	case "CompositeStrategy":
			        		//TODO
			        		break;
						}
						
						f1.setVisible(false);
					}
					
					
                	
                });
                
                
                p1.add(numberLabel);
                p1.add(numberField);
                
                p1.add(nameLabel);
                p1.add(nameField);
                
                p1.add(typeLabel);
                p1.add(typeField);
                
                
                p1.add(adapttypeLabel);
                p1.add(adapttypeField);
                
                
                p1.add(discountLabel);
                p1.add(discountField);
                
                p1.add(okButton);
                
                f1.add(p1);
                f1.setSize(300,300);
                f1.setModal(true);
                f1.setVisible(true);
                
                
				
			}
        	
        });
        
        deleteButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				int row = table.getSelectedRow();
				String number = (String) model.getValueAt(row, 0);
				controller.deleteStrategy(number);
				System.out.println(number);
				model.removeRow(row);
				
			}
        	
        });
        
        
        
        updateButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				// create all the objects to be used
				int row = table.getSelectedRow();
				String number = (String) model.getValueAt(row, 0);
				
                JLabel nameLabel = new JLabel("策略名称:");
                JLabel typeLabel = new JLabel("策略类型:");
                JLabel adapttypeLabel = new JLabel("适用图书类型:");
                JLabel discountLabel = new JLabel("优惠额度:");

                
                JTextField nameField = new JTextField(15);
                JTextField typeField = new JTextField(15);
                JTextField adapttypeField = new JTextField(15);
                JTextField discountField = new JTextField(15);

                JButton okButton = new JButton("ok");
                JPanel p1 = new JPanel();
                JDialog f1 = new JDialog();
                
                
                
                okButton.addActionListener(new ActionListener() {

					@Override
					public void actionPerformed(ActionEvent arg0) {
						// TODO Auto-generated method stub
						String s1,s2,s3,s4,s5;
						s1 = number;
						s2 = nameField.getText();
						s3 = typeField.getText();
						s4 = adapttypeField.getText();
						s5 = discountField.getText();
						
						switch(s3) {
						case "PercentageStrategy":
							PercentageStrategy ps = new PercentageStrategy(s1, s2 , Integer.parseInt(s4),Integer.parseInt(s5));
			        		controller.updateStrategy(ps);
			        		Object a[] = {
			                        s1,s2,s3,s4,s5
			                    };
			        		model.removeRow(row);
			            	model.addRow(a);
							break;
			        	case "FlatRateStrategy":
			        		FlatRateStrategy fs = new FlatRateStrategy(s1,s2,Double.valueOf(s5).doubleValue(),Integer.parseInt(s4));
			        		controller.updateStrategy(fs);
			        		Object b[] = {
			                        s1,s2,s3,s4,s5
			                    };
			        		model.removeRow(row);
			            	model.addRow(b);
			        		break;
			        	case "CompositeStrategy":
			        		//TODO
			        		break;
						}
						
						f1.setVisible(false);
					}
					
					
                	
                });
                
                
//                p1.add(numberLabel);
//                p1.add(numberField);
                
                p1.add(nameLabel);
                p1.add(nameField);
                
                p1.add(typeLabel);
                p1.add(typeField);
                
                
                p1.add(adapttypeLabel);
                p1.add(adapttypeField);
                
                
                p1.add(discountLabel);
                p1.add(discountField);
                
                p1.add(okButton);
                
                f1.add(p1);
                f1.setSize(300,300);
                f1.setModal(true);
                f1.setVisible(true);
                
                
				
			}
        	
        });
        
        
        
        
// add all the component to the panel
        panel.add(table);
        panel.add(addButton);
        panel.add(deleteButton);
        panel.add(updateButton);
        
        
// add the panel to the JDialog
        add(panel);
        
        
	}

}
