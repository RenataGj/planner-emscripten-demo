
(function($, Planner) {

  /**
   * Page component selectors.
   */
  const components = {
    addTodoButton: '#add-todo-button',
    todoDescription: '#todo-description',
    todoItems: '#todo-items',

    todoItem: {
      template: '#todo-item-template',
      description: '.description',
      toggle: '.done-flag'
    }
  };

  /**
   * Creates new DOM representation of the given Item.
   *
   * @param item the item (Planner.Item instance).
   * @param id the item id.
   * @return the jQuery wrapper of the newly created DOM element.
   */
  const createDOMItem = (item, id) => {

    /**
     * Updates the status of the represented item.
     *
     * @param $domItem the DOM (jQuery) reprensentation of the item.
     * @param nextStatus the next status of the item.
     */
    const updateStatus = ($domItem, nextStatus) => {
      item.status = nextStatus;

      if (item.status === Planner.Status.Complete.value) {
        $domItem.addClass('list-group-item-success');
      } else if (item.status === Planner.Status.Open.value) {
        $domItem.removeClass('list-group-item-success');
      } else {
        console.log('unsupported status', item.status);
      }
    };

    // create the DOM item
    const $domItem = $(components.todoItem.template).clone().removeAttr('id').data('id', id);
    $domItem.find(components.todoItem.description).text(item.description);

    $domItem.find(components.todoItem.toggle).click(e =>
      updateStatus($domItem, e.target.checked
        ? Planner.Status.Complete
        : Planner.Status.Open
      )
    );

    return $domItem;
  };

  // the object which holds all todo items
  const todos = new Planner.List('default');

  /**
   * A hanler which adds new item into the ToDo list
   */
  const handleTodoAdd = () => {
    const $todoDescription = $(components.todoDescription);

    if ($todoDescription.val()) {
      // instantiate item and add it to the list of todos
      const item = new Planner.Item($todoDescription.val());
      todos.addItem(item);

      // create the DOM element for the item
      createDOMItem(item, todos.getItemsCount()).appendTo($(components.todoItems));
      $todoDescription.val('');
    }
  };

  // event handlers
  $(components.addTodoButton).click(handleTodoAdd);
  $(components.todoDescription).keypress(e => {
    if (e.keyCode === 13) {
      handleTodoAdd();
    }
  });

})(jQuery, Module); // Module is wrapper object around compiled C++ code.
