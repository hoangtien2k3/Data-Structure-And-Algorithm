package BaiTap.baitap.bai1;

import java.util.ArrayList;
import java.util.Scanner;

class Document {
    private String documentCode;
    private String documentName;
    private String publisher;
    private double price;

    public Document(String documentCode, String documentName, String publisher, double price) {
        this.documentCode = documentCode;
        this.documentName = documentName;
        this.publisher = publisher;
        this.price = price;
    }

    public String getDocumentCode() {
        return documentCode;
    }

    public void setDocumentCode(String documentCode) {
        this.documentCode = documentCode;
    }

    public String getDocumentName() {
        return documentName;
    }

    public void setDocumentName(String documentName) {
        this.documentName = documentName;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}


class Book extends Document {
    private String author;
    private int numberOfPages;
    public Book(String documentCode, String documentName, String publisher, double price, String author, int numberOfPages) {
        super(documentCode, documentName, publisher, price);
        this.author = author;
        this.numberOfPages = numberOfPages;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getNumberOfPages() {
        return numberOfPages;
    }

    public void setNumberOfPages(int numberOfPages) {
        this.numberOfPages = numberOfPages;
    }
}


class Magazine extends Document {
    private int issueNumber;
    private int month;

    public Magazine(String documentCode, String documentName, String publisher, double price, int issueNumber, int month) {
        super(documentCode, documentName, publisher, price);
        this.issueNumber = issueNumber;
        this.month = month;
    }

    public int getIssueNumber() {
        return issueNumber;
    }

    public void setIssueNumber(int issueNumber) {
        this.issueNumber = issueNumber;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

}



class Newspaper extends Document {
    private String date;
    public Newspaper(String documentCode, String documentName, String publisher, double price, String date) {
        super(documentCode, documentName, publisher, price);
        this.date = date;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }
}


class BookManager {
    private ArrayList<Document> documents;
    public BookManager() {
        documents = new ArrayList<>();
    }

    public void addDocument() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("____________ BookManager ___________");
        System.out.println("\t1. Book");
        System.out.println("\t2. Magazine");
        System.out.println("\t3. Newspaper");
        System.out.println("____________________________________");
        System.out.print("Enter document type: ");
        int type = scanner.nextInt();
        scanner.nextLine(); // Clear the input buffer
        System.out.print("+ Enter document code: ");
        String code = scanner.nextLine();
        System.out.print("+ Enter document name: ");
        String name = scanner.nextLine();
        System.out.print("+ Enter publisher: ");
        String publisher = scanner.nextLine();
        System.out.print("+ Enter price: ");
        double price = scanner.nextDouble();
        scanner.nextLine(); // Clear the input buffer
        switch (type) {
            case 1:
                System.out.print("+ Enter author: ");
                String author = scanner.nextLine();
                System.out.print("+ Enter number of pages: ");
                int numberOfPages = scanner.nextInt();
                documents.add(new Book(code, name, publisher, price, author, numberOfPages));
                break;
            case 2:
                System.out.print("+ Enter issue number: ");
                int issueNumber = scanner.nextInt();
                System.out.print("+ Enter month: ");
                int month = scanner.nextInt();
                documents.add(new Magazine(code, name, publisher, price, issueNumber, month));
                break;
            case 3:
                scanner.nextLine(); // Clear the input buffer
                System.out.print("+ Enter date: ");
                String date = scanner.nextLine();
                documents.add(new Newspaper(code, name, publisher, price, date));
                break;
            default:
                System.out.println("=> Invalid document type!");
        }
    }

    public void displayDocuments() {
        for (Document document : documents) {
            System.out.println(document.toString());
        }
    }

    public void searchDocument() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("+ Enter document code: ");
        String code = scanner.nextLine();
        for (Document document : documents) {
            if (document.getDocumentCode().equals(code)) {
                System.out.println(document.toString());
                return;
            }
        }
        System.out.println("=> Document not found!");
    }
}

public class bai1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BookManager bookManager = new BookManager();
        while (true) {
            System.out.println("______________ Menu ________________");
            System.out.println("\t1. Add document");
            System.out.println("\t2. Display documents");
            System.out.println("\t3. Search document");
            System.out.println("\t4. Exit");
            System.out.println("____________________________________");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Clear the input buffer
            switch (choice) {
                case 1:
                    bookManager.addDocument();
                    break;
                case 2:
                    bookManager.displayDocuments();
                    break;
                case 3:
                    bookManager.searchDocument();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("=> Invalid choice!");
            }
        }
    }
}

