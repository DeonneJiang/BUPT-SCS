package homework7;

import java.util.Set;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;


public class AddBookUI extends JDialog{
	
	private Controller controller;
	
	
	public AddBookUI(Controller pcontroller) {
		setSize(800,600);
		controller = pcontroller;
		
		
// crate the panel
		JPanel panel = new JPanel();
		
		
// create the "add book" button 
		JButton addbookButton = new JButton("���ͼ��");
		
// create the table which shows all the books
		DefaultTableModel model = new DefaultTableModel();
        model.addColumn("ISBN");
        model.addColumn("����");
        model.addColumn("����");
        model.addColumn("��������");
        
        JTable table = new JTable(model);
        
        
        // add books to the table
        for( BookSpecification book : controller.getBookCatalog().books){
        	String s1 = new String(book.isbn);
        	String s2 = new String(book.title);
        	String s3 = Double.toString(book.price);
        	String s4;
        	switch(book.type) {
        	case 1: s4  = "�ǽ̲�������ͼ��"; break;
        	case 2: s4  = "�̲���ͼ��"; break;
        	case 3: s4  = "��������ͼ��"; break;
        	case 4: s4  = "������ͼ��"; break;
        	default : s4  = "����"; break;
        	}
            Object a[] = {
                s1,s2,s3,s4
            };
            model.addRow(a);
        }
        
// crate all the JText and JLabel
        JLabel isbnLabel = new JLabel("ISBN:");
        JLabel nameLabel = new JLabel("����:");
        JLabel priceLabel = new JLabel("����:");
        JLabel typeLabel = new JLabel("�������ͣ�ͼ������Ͱ�����1.�ǽ̲�������ͼ�顢2.�̲���ͼ�顢3.��������ͼ�顢4.������ͼ�顢5.���� ��5�֣�:");
        
        JTextField isbnField = new JTextField(10);
        JTextField nameField = new JTextField(10);
        JTextField priceField = new JTextField(10);
        JTextField typeField = new JTextField(10);
        
// attach the behavior to the button
        addbookButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				String bisbn,bname,bprice,btype;
				bisbn = isbnField.getText();
				bname = nameField.getText();
				bprice = priceField.getText();
				btype = typeField.getText();
				BookSpecification newbook = new BookSpecification(Double.valueOf(bprice).doubleValue(),bname, Integer.parseInt(btype),bisbn);
				controller.addBook(newbook);
				
				String s1 = new String(newbook.isbn);
	        	String s2 = new String(newbook.title);
	        	String s3 = Double.toString(newbook.price);
	        	String s4;
	        	switch(newbook.type) {
	        	case 1: s4  = "�ǽ̲�������ͼ��"; break;
	        	case 2: s4  = "�̲���ͼ��"; break;
	        	case 3: s4  = "��������ͼ��"; break;
	        	case 4: s4  = "������ͼ��"; break;
	        	default : s4  = "����"; break;
	        	}
	            Object a[] = {
	                s1,s2,s3,s4
	            };
	            model.addRow(a);
			}
        	
        });
		
// add all the component to the panel
        panel.add(table);
        panel.add(isbnLabel);
        panel.add(isbnField);
        panel.add(nameLabel);
        panel.add(nameField);
        panel.add(priceLabel);
        panel.add(priceField);
        panel.add(typeLabel);
        panel.add(typeField);
        panel.add(addbookButton);
        

// add the panel to the JDialog
        add(panel);
		
	}
}
