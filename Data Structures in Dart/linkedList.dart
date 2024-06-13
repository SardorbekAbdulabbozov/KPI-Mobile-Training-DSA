class Node {
  int value;
  Node? next;

  Node({required this.value, this.next});
}

class LinkedList {
  int length = 0;
  Node? head;
  Node? tail;

  LinkedList();

  void append(int newValue) {
    Node newNode = Node(value: newValue);
    if (tail == null) {
      head = newNode;
      tail = head;
    } else {
      tail?.next = newNode;
      tail = newNode;
    }
    length++;
  }

  void insertAt(int newValue, int index) {
    if (index < 0 || index > length) {
      print("ERROR: Index out of bounds");
      return;
    }

    if (index == 0) {
      Node newNode = Node(value: newValue, next: head);
      head = newNode;
      if (length == 0) {
        tail = newNode;
      }
    } else if (index == length) {
      append(newValue);
      return;
    } else {
      Node newNode = Node(value: newValue);
      Node? current = head;
      for (int i = 0; i < index - 1; i++) {
        current = current?.next;
      }
      newNode.next = current?.next;
      current?.next = newNode;
    }
    length++;
  }

  void removeLast() {
    if (tail == null) {
      print("List is empty");
      return;
    }
    if (head == tail) {
      head = null;
      tail = null;
    } else {
      Node? current = head;

      while (current?.next != tail) {
        current = current?.next;
      }

      current?.next = null;
      tail = current;
    }
    length--;
  }

  void removeAt(int index) {
    if (head == null) {
      print("List is empty");
      return;
    }
    if (index < 0 || index >= length) {
      print("ERROR: Index out of bounds");
      return;
    }

    if (index == 0) {
      head = head?.next;
      if (head == null) {
        tail = null;
      }
      length--;
    } else {
      Node? current = head;
      for (int i = 0; i < index - 1; i++) {
        current = current?.next;
      }
      current?.next = current.next?.next;
      if (current?.next == null) {
        tail = current;
      }
      length--;
    }
  }

  void traverseList() {
    if (head == null) {
      print("List is empty");
      return;
    }
    Node? current = head;

    print("--> Length = ${length}");
    while (current != null) {
      print(current.value);
      current = current.next;
    }
  }
}

void main() {
  LinkedList linkedList = LinkedList();

  linkedList.append(101);
  linkedList.append(234);
  linkedList.append(94);
  linkedList.append(27);
  linkedList.append(68);
  linkedList.insertAt(1, 0);
  linkedList.insertAt(2, 1);
  linkedList.insertAt(3, 2);
  linkedList.insertAt(5, 7);

  linkedList.traverseList();

  print('----------------');

  linkedList.removeLast();
  linkedList.removeAt(0);
  linkedList.removeAt(6);
  linkedList.removeAt(1);

  linkedList.traverseList();
}
