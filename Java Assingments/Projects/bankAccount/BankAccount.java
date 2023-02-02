package bankAccount;

public class BankAccount {
    // Write your code here
    // ...
    private String ownerName;
    private Double balance;

    public BankAccount() {
        this.ownerName = "NA";
        this.balance = 0.0;
    }

    public BankAccount(String ownerName) {
        this();
        this.ownerName = ownerName;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    private void print() {
        System.out.println("Name=" + this.getOwnerName());
        System.out.println("Balance=" + this.getBalance());
    }

    private void sendMoneyTo(double amount, BankAccount bankAccount) {
        this.setBalance(this.getBalance() - amount);
        bankAccount.setBalance(bankAccount.getBalance() + amount);
    }

    ///////////////////////////
    // DO NOT modify main method
    // or your question will not be evaluated!
    public static void main(String[] args) {
        BankAccount a1 = new BankAccount();
        BankAccount a2 = new BankAccount("Ali");
        System.out.println(a1.getOwnerName());
        System.out.println(a1.getBalance());
        System.out.println(a2.getOwnerName());
        System.out.println(a2.getBalance());
        a1.setOwnerName("Mehmet");
        a1.setBalance(1000);
        a1.sendMoneyTo(200, a2);
        a1.print();
        a2.print();
    }


}