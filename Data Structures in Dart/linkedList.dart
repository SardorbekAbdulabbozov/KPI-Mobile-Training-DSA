class Node {
  int value;
  Node? next;

  Node({required this.value, this.next});
}

class LinkedList {
  int length = 0;
  Node? head;

  LinkedList();

  void append(int newValue) {
    if (head == null) {
      head = Node(value: newValue);
    } else {
      Node newNode = Node(value: newValue);
      Node? current = head;

      while (current?.next != null) {
        current = current?.next;
      }
      current?.next = newNode;
    }
    length++;
  }

  void insertAt(int newValue, int index) {
    if (index < 0) {
      print("ERROR: Index out of bounds");
      return;
    }

    if (head == null) {
      head = Node(value: newValue);
      length++;
    } else {
      if (index < length) {
        Node? current = head;
        Node newNode = Node(value: newValue);

        for (int i = 0; i < index - 1; i++) {
          current = current?.next;
        }

        if (index == 0) {
          newNode.next = current;
          head = newNode;
          length++;
          return;
        }

        if (current?.next != null) {
          newNode.next = current?.next;
        }
        current?.next = newNode;
        length++;
      } else if (index == length) {
        append(newValue);
      } else {
        print("ERROR: Index out of bounds");
        return;
      }
    }
  }

  void removeLast() {
    if (head == null) {
      print("List is empty");
    } else if (head?.next == null) {
      head = null;
    } else {
      Node? current = head;

      while (current != null) {
        if (current.next?.next == null) {
          break;
        }
        current = current.next;
      }

      current?.next = null;
    }
    length--;
  }

  void removeAt(int index) {
    if (head == null) {
      print("List is empty");
      return;
    }
    if (index < 0) {
      print("ERROR: Index out of bounds");
      return;
    } else if (index == 0) {
      if (head?.next != null) {
        head = head?.next;
      } else {
        head = null;
      }
      length--;
    } else {
      if (index < length) {
        Node? current = head;
        for (int i = 0; i < index - 1; i++) {
          current = current?.next;
        }
        current?.next = current.next?.next != null ? current.next?.next : null;
        length--;
      } else {
        print("ERROR: Index out of bounds");
      }
    }
  }

  void traverseList() {
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
