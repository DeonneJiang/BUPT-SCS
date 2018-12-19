package homework7;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class MainUI extends JFrame{
	
	public static void main(String[] args) {
		MainUI mainUI = new MainUI();
		mainUI.setVisible(true);
		mainUI.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
	
	private Controller controller;
	private JPanel mainPanel;
	
	private static final int DEFAULT_WIDTH = 400;
    private static final int DEFAULT_HEIGHT = 300;
	
	
	public MainUI() {
		
		setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
		
		controller = new Controller();//Controller object must be create at once
		mainPanel = new JPanel();
		
		JButton addBookButton = new JButton("添加图书");
		JButton strategyManageButton = new JButton("策略管理");
		JButton buyBookButton = new JButton("购买图书");
		
		mainPanel.add(addBookButton);
		mainPanel.add(strategyManageButton);
		mainPanel.add(buyBookButton);
		
		addBookButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                AddBookUI adbUI = new AddBookUI(controller);
                setVisible(false);
                adbUI.setModal(true);
                adbUI.setVisible(true);
                setVisible(true);
            }
        });
		
		
		
		strategyManageButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				StrategiesUI strUI = new StrategiesUI(controller);
				setVisible(false);
				strUI.setModal(true);
				strUI.setVisible(true);
                setVisible(true);
			}
			
		});
		
		
		buyBookButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				BuyUI buyUI = new BuyUI(controller);
				buyUI.setVisible(true);
//				setVisible(false);
//				buyUI.setModal(true);
//				buyUI.setVisible(true);
//                setVisible(true);
			}
			
		});
		
		
		add(mainPanel);
		
		
	}
	
}
